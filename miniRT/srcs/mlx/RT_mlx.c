/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RT_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 13:42:28 by cmeunier          #+#    #+#             */
/*   Updated: 2020/03/11 11:36:52 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

void	ft_init_mlx(t_mlx *mlx, t_scene *scene)
{
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, scene->window_width, scene->window_height, "MiniRT");
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, scene->window_width, scene->window_height);
	mlx->img_data = (int*)mlx_get_data_addr(mlx->img_ptr, &mlx->bpp, &mlx->size_line, &mlx->endian);
}

int			rt_loop(t_mlx mlx)
{
	(void)mlx;
	return(0);
}

void	display_image(t_rt *rt)
{
	fill_img(rt->scene, rt->mlx);
	mlx_put_image_to_window(rt->mlx->mlx_ptr, rt->mlx->win_ptr, rt->mlx->img_ptr, 0, 0);
}

int		ft_key_switch(int key, t_rt *rt)
{
	if(key == 8)
	{
		rt->scene->cameras = rt->scene->cameras->next;
		rt->scene->active_camera = rt->scene->cameras->camera;
		display_image(rt);
		return(0);
	}
	else
		return(0);
}

int		ft_key_fov(int key, t_rt *rt)
{
	double increment_pos;

	increment_pos = 1;
	if(key == 87)
	{
		rt->scene->active_camera->fov += increment_pos;
		display_image(rt);
		return(0);
	}
	if(key == 91)
	{
		rt->scene->active_camera->fov -= increment_pos;
		display_image(rt);
		return(0);
	}
	else
		return(0);
}

int		ft_key_invert_colors(int key, t_rt *rt)
{
	if(key == 34)
	{
		if (rt->scene->invert)
			rt->scene->invert = 0;
		else
			rt->scene->invert = 1;
		display_image(rt);
		return(0);
	}
	else
		return(0);
}

int		ft_key_pos(int key, t_rt *rt)
{
	double increment_pos;

	increment_pos = 1;
	if(key == 126)
	{
		rt->scene->active_camera->pos = add_vec(rt->scene->active_camera->pos, mult_point_d(rt->scene->active_camera->dir_z, increment_pos));
		display_image(rt);
		return(0);
	}
	if(key == 125)
	{
		rt->scene->active_camera->pos = sub_vec(rt->scene->active_camera->pos, mult_point_d(rt->scene->active_camera->dir_z, increment_pos));
		display_image(rt);
		return(0);
	}
	if(key == 124)
	{
		rt->scene->active_camera->pos = add_vec(rt->scene->active_camera->pos, mult_point_d(rt->scene->active_camera->dir_x, increment_pos));
		display_image(rt);
		return(0);
	}
	if(key == 123)
	{
		rt->scene->active_camera->pos = sub_vec(rt->scene->active_camera->pos, mult_point_d(rt->scene->active_camera->dir_x, increment_pos));
		display_image(rt);
		return(0);
	}
	else
		return(0);
}

int		ft_key_rot(int key, t_rt *rt)
{
	double increment_rot;

	increment_rot = 0.1;
	if(key == 0)
	{
		rt->scene->active_camera->rot.y -= increment_rot;
		calc_camera_dir(rt->scene->active_camera);
		display_image(rt);
		return(0);
	}
	if(key == 2)
	{
		rt->scene->active_camera->rot.y += increment_rot;
		calc_camera_dir(rt->scene->active_camera);
		display_image(rt);
		return(0);
	}
	if(key == 13)
	{
		rt->scene->active_camera->rot.x -= increment_rot;
		calc_camera_dir(rt->scene->active_camera);
		display_image(rt);
		return(0);
	}
	if(key == 1)
	{
		rt->scene->active_camera->rot.x += increment_rot;
		calc_camera_dir(rt->scene->active_camera);
		display_image(rt);
		return(0);
	}
	else
		return(0);
}

int		ft_key_point_light(int key, t_rt *rt)
{
	double increment_light;
	t_lights *lights;

	lights = rt->scene->lights;
	increment_light = 0.05;
	if(key == 92)
	{
		while (lights)
		{
			if(lights->point_light->lum > increment_light)
				lights->point_light->lum -= increment_light;
			lights = lights->next;
		}
		display_image(rt);
		return(0);
	}
	if(key == 88)
	{
		while (lights)
		{
			lights->point_light->lum += increment_light;
			lights = lights->next;
		}
		display_image(rt);
		return(0);
	}
	if(key == 85)
	{
		while (lights)
		{
			lights->point_light->lum = 0.2;
			lights = lights->next;
		}
		display_image(rt);
		return(0);
	}
	return(0);
}

int		ft_key_ambient_light(int key, t_rt *rt)
{
	double increment_light;

	increment_light = 0.05;
	if(key == 53)
		exit_free_all(rt->scene);
	if(key == 78)
	{
		if(rt->scene->ambient_light.lum > increment_light)
			rt->scene->ambient_light.lum -= increment_light;
		display_image(rt);
		return(0);
	}
	if(key == 69)
	{
		rt->scene->ambient_light.lum += increment_light;
		display_image(rt);
		return(0);
	}
	if(key == 82)
	{
		rt->scene->ambient_light.lum = 0.5;
		display_image(rt);;
		return(0);
	}
	return(0);
}

int ft_key(int key, t_rt *rt)
{
	ft_key_ambient_light(key, rt);
	ft_key_point_light(key, rt);
	ft_key_pos(key, rt);
	ft_key_rot(key, rt);
	ft_key_switch(key, rt);
	ft_key_fov(key, rt);
	ft_key_invert_colors(key, rt);
	return(1);
}

int		quit_window(t_rt *rt, int code)
{
	(void)rt;
	(void)code;
	//exit_free_all(rt->scene);
	exit(0);
	return (0);
}

void	start_window(t_rt *rt)
{
	(void)rt;
	mlx_key_hook(rt->mlx->win_ptr, ft_key, rt);
	mlx_hook(rt->mlx->win_ptr, 17, 131072, quit_window, &rt);
	mlx_loop(rt->mlx->mlx_ptr);
}
