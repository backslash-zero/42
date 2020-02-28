/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 13:57:43 by cmeunier          #+#    #+#             */
/*   Updated: 2020/02/28 14:10:00 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

void	light_calc(t_color *color, double lum, t_color light_color)
{
	color->r = lum * color->r * (light_color.r / 255);
	color->g = lum * color->g * (light_color.g / 255);
	color->b = lum * color->b * (light_color.b / 255);
}

void	add_light(t_color *color, double new_i, t_color point_light_color)
{
	t_color addedcolor;

	addedcolor = *color;
	light_calc(&addedcolor, new_i, point_light_color);
	color->r = color->r + addedcolor.r;
	color->g = color->g + addedcolor.g;
	color->b = color->b + addedcolor.b;
}

void	convert_light_ray(t_ray *ray, t_ray *light_ray, t_light_vec *light_vec)
{
	light_ray->origin = ray->point;
	light_ray->dir =light_vec->dir;
}

void	process_light(t_scene *scene, t_ray *ray)
{	
	ray->point = add_vec(scene->active_camera->pos, mult_point_d(ray->dir, ray->closest_t));
	ray->normal = normal_calc(ray);
	point_light(scene, ray);
	ambient_light(scene, ray);
}

void	point_light(t_scene *scene, t_ray *ray)
{
	t_light_vec	light_vec;
	t_lights	*tmp;
	double		n_dot_l;
	double		new_i;
	t_ray		light_ray;
	
	n_dot_l = 0;
	new_i = 0;
	tmp = scene->lights;
	while(tmp)
	{
		light_vec.color = tmp->point_light->color;
		light_vec.lum = tmp->point_light->lum;
		light_vec.dir = sub_vec(tmp->point_light->pos, ray->point);
		
		n_dot_l = prod_scal(ray->normal, light_vec.dir);
		new_i = light_vec.lum * n_dot_l / (norm_vec(ray->normal)*norm_vec(light_vec.dir));

		convert_light_ray(ray, &light_ray, &light_vec);
		if(!shadow_intersection(&light_ray, scene, &light_vec))
		{
			if(n_dot_l > 0)
				add_light(&ray->color, new_i, light_vec.color);
			specular_light_processing(ray, &light_vec);
		}
		tmp = tmp->next;
	}
}
