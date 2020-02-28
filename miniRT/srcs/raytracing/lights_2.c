/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 13:48:26 by cmeunier          #+#    #+#             */
/*   Updated: 2020/02/28 13:58:32 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

void	ambient_lighting(t_color *color, t_scene *scene)
{
	color->r = scene->ambient_light.lum * color->r * (scene->ambient_light.color.r / 255);
	color->g = scene->ambient_light.lum * color->g * (scene->ambient_light.color.g / 255);
	color->b = scene->ambient_light.lum * color->b * (scene->ambient_light.color.b / 255);
}

void	ambient_light(t_scene *scene, t_ray *ray)
{
	light_calc(&ray->color, scene->ambient_light.lum, scene->ambient_light.color);
}

void	specular_light(t_ray *ray, double specular, t_light_vec *light_vec )
{
	t_vec	reflect;
	t_vec	v;
	double	r_dot_v;
	double	new_i;

	init_vec(&reflect);
	r_dot_v = 0;
	new_i = 0;
	v = mult_point_d(ray->dir, -1);
	if(specular != -1)
	{
		reflect = sub_vec(mult_point_d(ray->normal, 2 * prod_scal(ray->normal, light_vec->dir)), light_vec->dir);
		r_dot_v = prod_scal(reflect, v);
		new_i = light_vec->lum * pow(r_dot_v / (norm_vec(reflect) * norm_vec(v)), specular);
		if(r_dot_v > 0)
			add_light(&ray->color, new_i, light_vec->color);
	}
}

void	specular_light_processing(t_ray *ray, t_light_vec *light_vec)
{
	t_sphere *s_tmp;
	if(ray->closest_object->id == (int)'s')
	{
		s_tmp = (t_sphere *)ray->closest_object->obj;
		specular_light(ray, s_tmp->specular, light_vec);
	}
}

int		shadow_intersection(t_ray *light_ray, t_scene *scene, t_light_vec *light_vec)
{
	t_objects	*tmp;
	double		max;
	
	(void)light_vec;
	tmp = scene->objects;
	max = norm_vec(light_ray->dir);
	while(tmp)
	{
		intersect_object(light_ray, tmp);
		// > 0 or 0.0000001
		if(light_ray->inter.t1 > 0.000001 && light_ray->inter.t1 < max)
			return(1);
		if(light_ray->inter.t2 > 0.000001 && light_ray->inter.t2 < max)
			return(1);
		tmp = tmp->next;
	}
	return(0);
}
