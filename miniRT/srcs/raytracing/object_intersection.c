/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_intersection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:12:02 by cmeunier          #+#    #+#             */
/*   Updated: 2020/02/28 15:13:51 by cmeunier         ###   ########.fr       */
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
