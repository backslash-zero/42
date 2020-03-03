/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 14:27:46 by cmeunier          #+#    #+#             */
/*   Updated: 2020/03/03 15:42:15 by cmeunier         ###   ########.fr       */
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
	
	normal = sub_vec(ray->point, cylinder->pos);
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
