/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 13:48:26 by cmeunier          #+#    #+#             */
/*   Updated: 2020/03/12 19:30:26 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minirt.h"

void	specular_light(t_ray *ray, double specular, t_light_vec *light_vec)
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
		reflect = sub_vec(mult_point_d(ray->normal, 2 *
					prod_scal(ray->normal, light_vec->dir)), light_vec->dir);
		r_dot_v = prod_scal(reflect, v);
		new_i = light_vec->lum * pow(r_dot_v /
				(norm_vec(reflect) * norm_vec(v)), specular);
		if (r_dot_v > 0)
			add_light(&ray->color, new_i, light_vec->color);
	}
}

void	specular_light_processing_plane(t_ray *ray, t_light_vec *light_vec)
{
	t_plane		*p_tmp;
	t_square	*sq_tmp;
	t_triangle	*t_tmp;

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

void	specular_light_processing(t_ray *ray, t_light_vec *light_vec)
{
	t_sphere	*sp_tmp;
	t_cylinder	*cy_tmp;

	if (ray->closest_object->id == (int)'p' ||
		ray->closest_object->id == (int)'t' ||
		ray->closest_object->id == (int)'S')
		specular_light_processing_plane(ray, light_vec);
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
}
