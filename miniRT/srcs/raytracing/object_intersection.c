/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_intersection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:12:02 by cmeunier          #+#    #+#             */
/*   Updated: 2020/03/04 17:26:38 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

void intersect_ray_sphere(t_ray *ray, t_sphere *sphere)
{
	double k1;
	double k2;
	double k3;
    double discriminant;

	k1 = prod_scal(ray->dir, ray->dir);
    k2 = 2 * prod_scal(sub_vec(ray->origin, sphere->pos), ray->dir);
    k3 = prod_scal(sub_vec(ray->origin, sphere->pos), sub_vec(ray->origin, sphere->pos)) - (sphere->r * sphere->r);

    discriminant = (k2 * k2) - (4 * k1 * k3);
    if(discriminant < 0)
	{
		ray->inter.t1 = __DBL_MAX__;
		ray->inter.t2 = __DBL_MAX__;
	}
	else
	{
		ray->inter.t1 = (-k2 + sqrt(discriminant)) / (2 * k1);
		ray->inter.t2 = (-k2 - sqrt(discriminant)) / (2 * k1);
	}
}

void	intersect_ray_plane(t_ray *ray, t_plane *plane)
{
	double denom;

	denom = prod_scal(ray->dir, plane->normal);
	ray->inter.t2 = __DBL_MAX__;
	if(fabs(denom) > 0.000001)
	{
		ray->inter.t1 = prod_scal(sub_vec(plane->pos, ray->origin), plane->normal) / denom;
		if(ray->inter.t1 <= 0)
			ray->inter.t1 = __DBL_MAX__;
	}
	else
		ray->inter.t1 = __DBL_MAX__;
}

void	intersect_ray_square(t_ray *ray, t_square *square)
{
	int		hit;
	t_vec	inter;
	double denom;

	denom = prod_scal(ray->dir, square->normal);
	ray->inter.t2 = __DBL_MAX__;
	if(fabs(denom) > 0.000001)
	{
		ray->inter.t1 = prod_scal(sub_vec(square->pos, ray->origin), square->normal) / denom;
		if(ray->inter.t1 <= 0)
			ray->inter.t1 = __DBL_MAX__;
	}
	else
		ray->inter.t1 = __DBL_MAX__;
	if(ray->inter.t1 != __DBL_MAX__)
	{
		hit = 0;
		inter = add_vec(ray->origin, mult_point_d(ray->dir, ray->inter.t1));
		hit += prod_scal(cross_vec(sub_vec(square->point_1, inter), sub_vec(square->point_2, inter)), square->normal) > 0;
		hit += prod_scal(cross_vec(sub_vec(square->point_2, inter), sub_vec(square->point_3, inter)), square->normal) > 0;
		hit += prod_scal(cross_vec(sub_vec(square->point_3, inter), sub_vec(square->point_4, inter)), square->normal) > 0;
		hit += prod_scal(cross_vec(sub_vec(square->point_4, inter), sub_vec(square->point_1, inter)), square->normal) > 0;
		if (hit != 4 && hit != 0)
			ray->inter.t1 = __DBL_MAX__;
	}
}

void	intersect_ray_triangle(t_ray *ray, t_triangle *triangle)
{
		int		hit;
	t_vec	inter;
	double denom;

	denom = prod_scal(ray->dir, triangle->normal);
	ray->inter.t2 = __DBL_MAX__;
	if(fabs(denom) > 0.000001)
	{
		ray->inter.t1 = prod_scal(sub_vec(triangle->point_1, ray->origin), triangle->normal) / denom;
		if(ray->inter.t1 <= 0)
			ray->inter.t1 = __DBL_MAX__;
	}
	else
		ray->inter.t1 = __DBL_MAX__;
	if(ray->inter.t1 != __DBL_MAX__)
	{
		hit = 0;
		inter = add_vec(ray->origin, mult_point_d(ray->dir, ray->inter.t1));
		hit += prod_scal(cross_vec(sub_vec(triangle->point_1, inter), sub_vec(triangle->point_2, inter)), triangle->normal) > 0;
		hit += prod_scal(cross_vec(sub_vec(triangle->point_2, inter), sub_vec(triangle->point_3, inter)), triangle->normal) > 0;
		hit += prod_scal(cross_vec(sub_vec(triangle->point_3, inter), sub_vec(triangle->point_1, inter)), triangle->normal) > 0;
		if (hit != 3 && hit != 0)
			ray->inter.t1 = __DBL_MAX__;
	}
}

void	intersect_ray_cylinder(t_ray *ray, t_cylinder *cylinder)
{
	(void)ray;
	(void)cylinder;
}
