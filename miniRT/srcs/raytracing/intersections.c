/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:18:36 by cmeunier          #+#    #+#             */
/*   Updated: 2020/02/28 14:21:26 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

void	intersect_object(t_ray *ray, t_objects *tmp)
{
	if(tmp->id == (int)'s')
		intersect_ray_sphere(ray, tmp->obj);
	/*
	if(tmp->id == (int)'c')
	if(tmp->id == (int)'t')
	if(tmp->id == (int)'p')
	if(tmp->id == (int)'s')
	if(tmp->id == (int)'s')
	*/
}

t_vec	normal_calc(t_ray *ray)
{
	t_vec		normal;
	t_sphere	*tmp_s;

	init_vec(&normal);
	if(ray->closest_object->id == (int)'s')
	{
		tmp_s = (t_sphere *)ray->closest_object->obj;
		normal = sub_vec(ray->point, tmp_s->pos);
	}
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
