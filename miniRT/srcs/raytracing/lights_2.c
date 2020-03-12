/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 13:48:26 by cmeunier          #+#    #+#             */
/*   Updated: 2020/03/12 14:20:57 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minirt.h"

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

	init_vec(&reflect, 0, 0, 0);
	r_dot_v = 0;
	new_i = 0;
	v = mult_point_d(ray->dir, -1);
	if (specular != -1)
	{
		reflect = sub_vec(mult_point_d(ray->normal, 2 * prod_scal(ray->normal, light_vec->dir)), light_vec->dir);
		r_dot_v = prod_scal(reflect, v);
		new_i = light_vec->lum * pow(r_dot_v / (norm_vec(reflect) * norm_vec(v)), specular);
		if (r_dot_v > 0)
			add_light(&ray->color, new_i, light_vec->color);
	}
}

void	specular_light_processing(t_ray *ray, t_light_vec *light_vec)
{
	t_sphere *sp_tmp;
	t_cylinder *cy_tmp;
	t_plane *p_tmp;
	t_square *sq_tmp;
	t_triangle *t_tmp;
	if (ray->closest_object->id == (int)'s')
	{
		sp_tmp = (t_sphere *)ray->closest_object->obj;
		specular_light(ray, sp_tmp->specular, light_vec);
	}
	if (ray->closest_object->id == (int)'c')
	{
		cy_tmp = (t_cylinder *)ray->closest_object->obj;
		specular_light(ray, cy_tmp->specular, light_vec);
	}
	if (ray->closest_object->id == (int)'p')
	{
		p_tmp = (t_plane *)ray->closest_object->obj;
		specular_light(ray, p_tmp->specular, light_vec);
	}
	if (ray->closest_object->id == (int)'t')
	{
		t_tmp = (t_triangle *)ray->closest_object->obj;
		specular_light(ray, t_tmp->specular, light_vec);
	}
	if (ray->closest_object->id == (int)'S')
	{
		sq_tmp = (t_square *)ray->closest_object->obj;
		specular_light(ray, sq_tmp->specular, light_vec);
	}
}

int		shadow_intersection(t_ray *l_ray, t_scene *scene, t_light_vec *l_vec)
{
	t_objects	*tmp;
	double		max;
	
	(void)l_vec;
	tmp = scene->objects;
	max = norm_vec(l_ray->dir);
	while (tmp)
	{
		intersect_object(l_ray, tmp);
		if (l_ray->inter.t1 > 0.000001 && l_ray->inter.t1 < max)
			return (1);
		if (l_ray->inter.t2 > 0.000001 && l_ray->inter.t2 < max)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
