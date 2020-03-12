/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 19:13:07 by cmeunier          #+#    #+#             */
/*   Updated: 2020/03/12 19:30:52 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minirt.h"

void	light_if_shadow(t_ray *ray, double i, t_light_vec l_v)
{
	add_light(&ray->color, i, l_v.color);
	specular_light_processing(ray, &l_v);
}

void	ambient_lighting(t_color *color, t_scene *scene)
{
	color->r = scene->ambient_light.lum * color->r *
				(scene->ambient_light.color.r / 255);
	color->g = scene->ambient_light.lum * color->g *
				(scene->ambient_light.color.g / 255);
	color->b = scene->ambient_light.lum * color->b *
				(scene->ambient_light.color.b / 255);
}

void	ambient_light(t_scene *scene, t_ray *ray)
{
	light_calc(&ray->color, scene->ambient_light.lum,
				scene->ambient_light.color);
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
