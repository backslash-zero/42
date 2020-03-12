/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_bindings_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 15:38:32 by cmeunier          #+#    #+#             */
/*   Updated: 2020/03/12 15:39:22 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minirt.h"

int		ft_key_switch(int key, t_rt *rt)
{
	if (key == 8)
	{
		rt->scene->cameras = rt->scene->cameras->next;
		rt->scene->active_camera = rt->scene->cameras->camera;
		display_image(rt);
		return (0);
	}
	else
		return (0);
}

int		ft_key_fov(int key, t_rt *rt)
{
	double increment_pos;

	increment_pos = 1;
	if (key == 87)
	{
		rt->scene->active_camera->fov += increment_pos;
		display_image(rt);
		return (0);
	}
	if (key == 91)
	{
		rt->scene->active_camera->fov -= increment_pos;
		display_image(rt);
		return (0);
	}
	else
		return (0);
}

int		ft_key_invert_colors(int key, t_rt *rt)
{
	if (key == 34)
	{
		if (rt->scene->invert)
			rt->scene->invert = 0;
		else
			rt->scene->invert = 1;
		display_image(rt);
		return (0);
	}
	else
		return (0);
}
