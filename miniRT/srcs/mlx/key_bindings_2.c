/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_bindings_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 15:38:32 by cmeunier          #+#    #+#             */
/*   Updated: 2020/04/22 21:10:23 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minirt.h"

int		ft_key_switch(int key, t_rt *rt)
{
	if (key == 99)
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
	if (key == 111)
	{
		rt->scene->active_camera->fov += increment_pos;
		display_image(rt);
		return (0);
	}
	if (key == 108)
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
	if (key == 105)
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
