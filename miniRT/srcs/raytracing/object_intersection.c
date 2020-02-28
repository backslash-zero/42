/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_intersection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:12:02 by cmeunier          #+#    #+#             */
/*   Updated: 2020/02/28 14:21:20 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

void intersect_ray_sphere(t_ray *ray, t_sphere *sphere)
{
	t_vec oc;
	double k1;
	double k2;
	double k3;

	oc = sub_vec(ray->origin, sphere->pos);
	k1 = prod_scal(ray->dir, ray->dir);
    k2 = 2 * prod_scal(oc, ray->dir);
    k3 = prod_scal(oc, oc) - (sphere->r * sphere->r);

    double discriminant = (k2 * k2) - (4 * k1 * k3);
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
