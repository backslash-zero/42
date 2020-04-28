/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_intersection_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 19:03:05 by cmeunier          #+#    #+#             */
/*   Updated: 2020/04/28 15:16:08 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minirt.h"

void	intersect_ray_triangle_2(t_ray *ray, t_triangle *triangle)
{
	int		hit;
	t_vec	inter;

	hit = 0;
	inter = add_vec(ray->origin, mult_point_d(ray->dir, ray->inter.t1));
	hit += prod_scal(cross_vec(sub_vec(triangle->point_1, inter),
			sub_vec(triangle->point_2, inter)), triangle->normal) > 0;
	hit += prod_scal(cross_vec(sub_vec(triangle->point_2, inter),
			sub_vec(triangle->point_3, inter)), triangle->normal) > 0;
	hit += prod_scal(cross_vec(sub_vec(triangle->point_3, inter),
			sub_vec(triangle->point_1, inter)), triangle->normal) > 0;
	if (!(hit == 3 || hit == 0))
		ray->inter.t1 = __DBL_MAX__;
}

void	intersect_ray_triangle(t_ray *ray, t_triangle *triangle)
{
	double denom;

	denom = prod_scal(ray->dir, triangle->normal);
	ray->inter.t2 = __DBL_MAX__;
	if (fabs(denom) > 0.000001)
	{
		ray->inter.t1 = prod_scal(sub_vec(triangle->point_1, ray->origin),
						triangle->normal) / denom;
		if (ray->inter.t1 <= 0)
			ray->inter.t1 = __DBL_MAX__;
	}
	else
		ray->inter.t1 = __DBL_MAX__;
	if (ray->inter.t1 != __DBL_MAX__)
		intersect_ray_triangle_2(ray, triangle);
}

void	intersect_ray_cy_2(t_ray *r, t_cylinder *cy, t_vec d, t_vec a)
{
	t_vec	tmp1;
	t_vec	tmp2;

	d.y = (-a.y - sqrt(d.x)) / (2 * a.x);
	d.z = (-a.y + sqrt(d.x)) / (2 * a.x);
	tmp1 = add_vec(r->origin, mult_point_d(r->dir, d.y));
	tmp2 = add_vec(r->origin, mult_point_d(r->dir, d.z));
	if (d.y > 0.00001 && prod_scal(cy->dir,
			sub_vec(tmp1, cy->pos)) > 0 &&
		prod_scal(mult_point_d(cy->dir, -1),
				sub_vec(tmp1, cy->pos2)) > 0)
		r->inter.t1 = d.y;
	else
	{
		if (d.z > 0.00001 && prod_scal(cy->dir,
				sub_vec(tmp2, cy->pos)) > 0 &&
			prod_scal(mult_point_d(cy->dir, -1),
					sub_vec(tmp2, cy->pos2)) > 0)
			r->inter.t2 = d.z;
		else
			r->inter.t2 = __DBL_MAX__;
	}
}

void	intersect_ray_cylinder(t_ray *ray, t_cylinder *cylinder)
{
	t_vec	tmp1;
	t_vec	tmp2;
	t_vec	tmp3;
	t_vec	abc;
	t_vec	delta;

	ray->inter.t1 = __DBL_MAX__;
	ray->inter.t2 = __DBL_MAX__;
	tmp1 = sub_vec(ray->dir, mult_point_d(cylinder->dir,
			prod_scal(cylinder->dir, ray->dir)));
	tmp2 = sub_vec(ray->origin, cylinder->pos);
	tmp3 = sub_vec(tmp2, mult_point_d(cylinder->dir,
			prod_scal(tmp2, cylinder->dir)));
	abc.x = prod_scal(tmp1, tmp1);
	abc.y = 2 * prod_scal(tmp1, tmp3);
	abc.z = prod_scal(tmp3, tmp3) - cylinder->r * cylinder->r;
	if ((delta.x = (abc.y * abc.y) - 4 * abc.x * abc.z) < 0)
	{
		ray->inter.t1 = __DBL_MAX__;
		ray->inter.t2 = __DBL_MAX__;
	}
	else
		intersect_ray_cy_2(ray, cylinder, delta, abc);
}
