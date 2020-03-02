/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RT_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 13:42:28 by cmeunier          #+#    #+#             */
/*   Updated: 2020/03/02 14:27:56 by cmeunier         ###   ########.fr       */
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

// delete?
/* int		ft_key_camera(int key, t_scene *scene)
{
		if(key == 8)
		{
			printf("hey\n");
			//scene->cameras = scene->cameras->next;
			scene->ambient_light.lum += 0.2; 
			//scene->active_camera = scene->cameras->camera;
			return(0);
		}
		else
			return(0);
} */

int		ft_key(int key, t_rt *rt)
{
		printf("pressed key: %d\n", key);
		if(key == 53)
			exit(0);
		if(key == 78)
		{
			if(rt->scene->ambient_light.lum > 0.05)
				rt->scene->ambient_light.lum -= 0.05;
			fill_img(rt->scene, rt->mlx);
			return(0);
		}
		if(key == 69)
		{
			rt->scene->ambient_light.lum += 0.05;
			fill_img(rt->scene, rt->mlx);
			return(0);
		}
		if(key == 82)
		{
			rt->scene->ambient_light.lum = 0.5;
			fill_img(rt->scene, rt->mlx);
			return(0);
		}
		if(key == 8)
		{
			rt->scene->cameras = rt->scene->cameras->next;
			rt->scene->active_camera = rt->scene->cameras->camera;
			fill_img(rt->scene, rt->mlx);
			return(0);
		}
		else
			return(0);
}

void	start_window(t_rt *rt)
{
	(void)rt;
	mlx_key_hook(rt->mlx->win_ptr, ft_key, rt);
	mlx_loop(rt->mlx->mlx_ptr);
}
