/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:18:36 by cmeunier          #+#    #+#             */
/*   Updated: 2020/03/03 15:38:49 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

void	intersect_object(t_ray *ray, t_objects *tmp)
{
	if(tmp->id == (int)'s')
		intersect_ray_sphere(ray, tmp->obj);
	if(tmp->id == (int)'c')
		intersect_ray_cylinder(ray, tmp->obj);
	if(tmp->id == (int)'t')
		intersect_ray_triangle(ray, tmp->obj);
	if(tmp->id == (int)'p')
		intersect_ray_plane(ray, tmp->obj);
	if(tmp->id == (int)'S')
		intersect_ray_square(ray, tmp->obj);
}

t_vec	normal_calc(t_ray *ray)
{
	t_vec		normal;

	init_vec(&normal, 0, 0, 0);
	if(ray->closest_object->id == (int)'s')
		normal = normal_sphere(ray, ray->closest_object->obj);
	if(ray->closest_object->id == (int)'c')
		normal = normal_cylinder(ray, ray->closest_object->obj);
	if(ray->closest_object->id == (int)'t')
		normal = normal_triangle(ray->closest_object->obj);
	if(ray->closest_object->id == (int)'p')
		normal = normal_plane(ray->closest_object->obj);
	if(ray->closest_object->id == (int)'S')
		normal = normal_square(ray->closest_object->obj);
	normal = normalized(normal);
	return(normal);
}

void	intersection(t_ray *ray, t_scene *scene)
{
	t_objects	*tmp;

	tmp = scene->objects;

	ray->closest_object = NULL;
	ray->closest_t = __DBL_MAX__;
	while(tmp)
	{
		intersect_object(ray, tmp);
		if(ray->inter.t1 > 0 && ray->inter.t1 < __DBL_MAX__ && ray->inter.t1 < ray->closest_t)
		{
			ray->closest_t = ray->inter.t1;
			ray->closest_object = tmp;
		}
		if(ray->inter.t2 > 0 && ray->inter.t2 < __DBL_MAX__ && ray->inter.t2 < ray->closest_t)
		{
			ray->closest_t = ray->inter.t2;
			ray->closest_object = tmp;
		}
		// put white if no sphere interesection was found.
		if(ray->closest_object != NULL)
			ray->color = color_by_type_cast(ray->closest_object);
		tmp = tmp->next;
	}
}
