/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 14:27:46 by cmeunier          #+#    #+#             */
/*   Updated: 2020/03/03 14:46:37 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

t_vec	normal_sphere(t_ray *ray, t_sphere *sphere)
{
	t_vec normal;
	
	normal = sub_vec(ray->point, sphere->pos);
	return(normal);
}

t_vec	normal_triangle(t_ray *ray, t_triangle *triangle)
{
	t_vec normal;
	
	normal = sub_vec(ray->point, triangle->point_1);
	return(normal);
}

t_vec	normal_plane(t_ray *ray, t_plane *plane)
{
	t_vec normal;
	
	normal = sub_vec(ray->point, plane->pos);
	return(normal);
}

t_vec	normal_cylinder(t_ray *ray, t_cylinder *cylinder)
{
	t_vec normal;
	
	normal = sub_vec(ray->point, cylinder->pos);
	return(normal);
}

t_vec	normal_square(t_ray *ray, t_square *square)
{
	t_vec normal;
	
	normal = sub_vec(ray->point, square->pos);
	return(normal);
}
