/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 14:27:46 by cmeunier          #+#    #+#             */
/*   Updated: 2020/03/10 15:43:06 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

t_vec	normal_sphere(t_ray *ray, t_sphere *sphere)
{
	t_vec normal;
	
	normal = sub_vec(ray->point, sphere->pos);
	return(normal);
}

t_vec	normal_cylinder(t_ray *ray, t_cylinder *cylinder)
{
	t_vec normal;

	normal = sub_vec(cylinder->pos, ray->origin);
	normal = normalized(cross_vec(normal, cylinder->dir));
	normal = cross_vec(normal, cylinder->dir);
	return(normal);
}

t_vec	normal_square(t_square *square)
{
	return(square->normal);
}

t_vec	normal_triangle(t_triangle *triangle)
{
	return(triangle->normal);
}

t_vec	normal_plane(t_plane *plane)
{
	return(plane->normal);
}

/* 
t_vec3	sphere_normal(t_obj3d *obj, t_vec3 p, t_vec3 o)
{
	t_sphere	*ptr;
	t_vec3		v;
	double		m;

	(void)o;
	ptr = (t_sphere*)(obj->obj);
	v = v3sub(p, ptr->pos);
	m = v3magnitude(v);
	return (v3new(v.x / m, v.y / m, v.z / m));
}

t_vec3	cylinder_normal(t_obj3d *obj, t_vec3 p, t_vec3 o)
{
	t_vec3		v;
	t_cylinder	*ptr;

	(void)o;
	ptr = (t_cylinder*)obj->obj;
	v = v3sub(ptr->pos, p);
	v = v3normalize(v3cross(v, ptr->dir));
	return (v3cross(v, ptr->dir));
} */
