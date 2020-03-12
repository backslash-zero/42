/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:06:14 by cmeunier          #+#    #+#             */
/*   Updated: 2020/03/12 18:26:21 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minirt.h"

int		center_x(int x, t_scene *scene)
{
	x = -(scene->window_width / 2) + x;
	return (x);
}

int		center_y(int y, t_scene *scene)
{
	y = (scene->window_height / 2) - y;
	return (y);
}

double	get_vp_x(int x, t_scene *scene)
{
	double vp_x;

	vp_x = (double)x * scene->viewport_width / scene->window_width;
	return (vp_x);
}

double	get_vp_y(int y, t_scene *scene)
{
	double vp_y;

	vp_y = (double)y * scene->viewport_height / scene->window_height;
	return (vp_y);
}
