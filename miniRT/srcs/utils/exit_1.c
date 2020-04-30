/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 16:54:23 by cmeunier          #+#    #+#             */
/*   Updated: 2020/04/30 23:26:18 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minirt.h"

void	exit_success(t_rt *rt)
{
	free_all(rt);
	write(1, "\e[1;32mExiting, everything went well.\n\e[0m", 42);
	exit(SUCCESS);
}

void	parsing_err(t_rt *rt, char *msg, int n)
{
	char *line_n;

	free_all(rt);
	write(1, "Error", 6);
	write(1, "\e[1;31m", 7);
	write(1, msg, ft_strlen(msg));
	if (n != -1)
	{
		line_n = ft_itoa(++n);
		write(1, " on line ", 10);
		write(1, line_n, ft_strlen(line_n));
	}
	write(1, "\n\e[0m", 5);
	exit(FAILURE);
}

void	exit_failure(t_rt *rt)
{
	free_all(rt);
	perror("Error");
	write(1, "\e[1;31mExiting, there was an error.\n\e[0m", 40);
	exit(FAILURE);
}

void	free_all(t_rt *rt)
{
	free_cameras(rt->scene->cameras);
	free_objects(rt->scene->objects);
	free_lights(rt->scene->lights);
	if (rt->mlx->mlx_ptr)
	{
		if (rt->mlx->img_ptr)
			mlx_destroy_image(rt->mlx->mlx_ptr, rt->mlx->img_ptr);
		mlx_destroy_window(rt->mlx->mlx_ptr, rt->mlx->win_ptr);
	}
}

void	exit_free_all(t_scene *scene)
{
	free_cameras(scene->cameras);
	free_objects(scene->objects);
	free_lights(scene->lights);
	(void)scene;
	exit(0);
}
