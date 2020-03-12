/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_bindings_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 15:38:35 by cmeunier          #+#    #+#             */
/*   Updated: 2020/03/12 16:47:05 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minirt.h"

int		ft_key_pos(int key, t_rt *rt)
{
	double	increment_pos;

	increment_pos = 1;
	if ((key == 126) || (key == 125) || (key == 124) || (key == 123))
	{
		if (key == 126)
			rt->scene->active_camera->pos = add_vec(
				rt->scene->active_camera->pos,
				mult_point_d(rt->scene->active_camera->dir_z, increment_pos));
		if (key == 125)
			rt->scene->active_camera->pos = sub_vec(
				rt->scene->active_camera->pos,
				mult_point_d(rt->scene->active_camera->dir_z, increment_pos));
		if (key == 124)
			rt->scene->active_camera->pos = add_vec(
				rt->scene->active_camera->pos,
				mult_point_d(rt->scene->active_camera->dir_x, increment_pos));
		if (key == 123)
			rt->scene->active_camera->pos = sub_vec(
				rt->scene->active_camera->pos,
				mult_point_d(rt->scene->active_camera->dir_x, increment_pos));
		display_image(rt);
	}
	return (0);
}

int		ft_key_rot(int key, t_rt *rt)
{
	double	increment_rot;

	increment_rot = 0.1;
	if ((key == 0) || (key == 2) || (key == 13) || (key == 1))
	{
		if (key == 0)
			rt->scene->active_camera->rot.y -= increment_rot;
		if (key == 2)
			rt->scene->active_camera->rot.y += increment_rot;
		if (key == 13)
			rt->scene->active_camera->rot.x -= increment_rot;
		if (key == 1)
			rt->scene->active_camera->rot.x += increment_rot;
	}
	calc_camera_dir(rt->scene->active_camera);
	display_image(rt);
	return (0);
}

int		ft_key_point_light(int key, t_rt *rt)
{
	double		increment_light;
	t_lights	*lights;

	lights = rt->scene->lights;
	increment_light = 0.05;
	if ((key == 92) || (key == 88) || (key == 85))
	{
		while (lights)
		{
			if (key == 92)
				if (lights->point_light->lum > increment_light)
					lights->point_light->lum -= increment_light;
			if (key == 88)
				lights->point_light->lum += increment_light;
			if (key == 85)
				lights->point_light->lum = 0.2;
			lights = lights->next;
		}
		display_image(rt);
	}
	return (0);
}

int		ft_key_ambient_light(int key, t_rt *rt)
{
	double	increment_light;

	increment_light = 0.05;
	if ((key == 53) || (key == 78) || (key == 69) || (key == 82))
	{
		if (key == 53)
			exit_success(rt);
		if (key == 78)
			if (rt->scene->ambient_light.lum > increment_light)
				rt->scene->ambient_light.lum -= increment_light;
		if (key == 69)
			rt->scene->ambient_light.lum += increment_light;
		if (key == 82)
			rt->scene->ambient_light.lum = 0.5;
		display_image(rt);
	}
	return (0);
}

int		ft_key(int key, t_rt *rt)
{
	ft_key_ambient_light(key, rt);
	ft_key_point_light(key, rt);
	ft_key_pos(key, rt);
	ft_key_rot(key, rt);
	ft_key_switch(key, rt);
	ft_key_fov(key, rt);
	ft_key_invert_colors(key, rt);
	return (1);
}
