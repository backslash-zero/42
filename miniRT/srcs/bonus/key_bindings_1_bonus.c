/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_bindings_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 15:38:35 by cmeunier          #+#    #+#             */
/*   Updated: 2020/04/30 18:43:55 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minirt.h"

int		ft_key_pos(int key, t_rt *rt)
{
	double	increment_pos;

	increment_pos = 1;
	if ((key == 65362) || (key == 65363) || (key == 65361) || (key == 65364))
	{
		if (key == 65362)
			rt->scene->active_camera->pos = add_vec(
				rt->scene->active_camera->pos,
				mult_point_d(rt->scene->active_camera->dir_z, increment_pos));
		if (key == 65364)
			rt->scene->active_camera->pos = sub_vec(
				rt->scene->active_camera->pos,
				mult_point_d(rt->scene->active_camera->dir_z, increment_pos));
		if (key == 65363)
			rt->scene->active_camera->pos = add_vec(
				rt->scene->active_camera->pos,
				mult_point_d(rt->scene->active_camera->dir_x, increment_pos));
		if (key == 65361)
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
	if ((key == 100) || (key == 122) || (key == 113) || (key == 115))
	{
		if (key == 113)
			rt->scene->active_camera->rot.y -= increment_rot;
		if (key == 100)
			rt->scene->active_camera->rot.y += increment_rot;
		if (key == 122)
			rt->scene->active_camera->rot.x -= increment_rot;
		if (key == 115)
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
	if ((key == 109) || (key == 112) || (key == 224))
	{
		while (lights)
		{
			if (key == 109)
				if (lights->point_light->lum > increment_light)
					lights->point_light->lum -= increment_light;
			if (key == 112)
				lights->point_light->lum += increment_light;
			if (key == 224)
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
	if ((key == 65104) || (key == 65106) || (key == 41))
	{
		if (key == 65104)
			if (rt->scene->ambient_light.lum > increment_light)
				rt->scene->ambient_light.lum -= increment_light;
		if (key == 65106)
			rt->scene->ambient_light.lum += increment_light;
		if (key == 41)
			rt->scene->ambient_light.lum = 0.5;
		display_image(rt);
	}
	return (0);
}

int		ft_key(int key, t_rt *rt)
{
	ft_key_exit(key, rt);
	ft_key_switch(key, rt);
	ft_key_ambient_light(key, rt);
	ft_key_point_light(key, rt);
	ft_key_pos(key, rt);
	ft_key_rot(key, rt);
	ft_key_fov(key, rt);
	ft_key_invert_colors(key, rt);
	return (1);
}
