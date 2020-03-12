/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 22:07:41 by cmeunier          #+#    #+#             */
/*   Updated: 2020/03/12 17:14:49 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minirt.h"

void	rotation_calc(t_vec *vec, t_vec rot)
{
	x_rotation(vec, rad(rot_to_deg(rot.x)));
	y_rotation(vec, rad(rot_to_deg(rot.y)));
	z_rotation(vec, rad(rot_to_deg(rot.z)));
}

void	x_rotation(t_vec *dir, double angle)
{
	t_vec tmp;

	tmp.x = (1 * dir->x) + (0 * dir->y) + (0 * dir->z);
	tmp.y = (0 * dir->x) + (cos(angle) * dir->y) + (-sin(angle) * dir->z);
	tmp.z = (0 * dir->x) + (sin(angle) * dir->y) + (cos(angle) * dir->z);
	*dir = tmp;
}

void	y_rotation(t_vec *dir, double angle)
{
	t_vec tmp;

	tmp.x = (cos(angle) * dir->x) + (0 * dir->y) + (sin(angle) * dir->z);
	tmp.y = (0 * dir->x) + (1 * dir->y) + (0 * dir->z);
	tmp.z = (-sin(angle) * dir->x) + (0 * dir->y) + (cos(angle) * dir->z);
	*dir = tmp;
}

void	z_rotation(t_vec *dir, double angle)
{
	t_vec tmp;

	tmp.x = (cos(angle) * dir->x) + (-sin(angle) * dir->y) + (0 * dir->z);
	tmp.y = (sin(angle) * dir->x) + (cos(angle) * dir->y) + (0 * dir->z);
	tmp.z = (0 * dir->x) + (0 * dir->y) + (1 * dir->z);
	*dir = tmp;
}
