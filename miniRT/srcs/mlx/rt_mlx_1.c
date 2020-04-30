/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_mlx_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 13:42:28 by cmeunier          #+#    #+#             */
/*   Updated: 2020/04/30 19:35:27 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minirt.h"

int		quit_window(t_rt *rt, int code)
{
	(void)rt;
	(void)code;
	write(1, "\e[1;32mExiting, everything went well.\n\e[0m", 42);
	exit(SUCCESS);
	return (0);
}

void	put_image(t_rt *rt)
{
	mlx_put_image_to_window(rt->mlx->mlx_ptr,
		rt->mlx->win_ptr, rt->mlx->img_ptr, 0, 0);
}

void	put_image_and_start(t_rt *rt)
{
	rt->mlx->win_ptr = mlx_new_window(rt->mlx->mlx_ptr,
				rt->scene->window_width, rt->scene->window_height, "MiniRT");
	put_image(rt);
	start_window(rt);
}

void	display_image(t_rt *rt)
{
	fill_img(rt->scene, rt->mlx);
	put_image(rt);
}

void	start_window(t_rt *rt)
{
	(void)rt;
	mlx_key_hook(rt->mlx->win_ptr, ft_key, rt);
	mlx_hook(rt->mlx->win_ptr, 17, 131072, quit_window, &rt);
	mlx_loop(rt->mlx->mlx_ptr);
}
