/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 13:04:12 by cmeunier          #+#    #+#             */
/*   Updated: 2020/03/11 18:09:11 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

void	free_lights(t_lights *lights)
{
	t_lights *tmp;

	while(lights)
	{
		tmp = lights;
		lights = lights->next;
		free(tmp->point_light);
		free(tmp);
	}
}

void	free_objects(t_objects *objects)
{
	t_objects *tmp;

	while(objects)
	{
		tmp = objects;
		objects = objects->next;
		free(tmp->obj);
		free(tmp);
	}
}

void	free_cameras(t_cameras *cameras)
{
	t_cameras *tmp;
	t_cameras *first;

	first = cameras;

	while(cameras)
	{
		tmp = cameras;
		cameras = cameras->next;
		free(tmp->camera);
		free(tmp);
		if(cameras == first)
			cameras = NULL;
	}
}

void	exit_success(t_scene *scene)
{
	free_all(scene);
	write(1, "\e[1;32mExiting, everything went well.\n\e[0m", 42);
	exit(SUCCESS);
}

void	parsing_err(t_rt *rt, char *msg, int n)
{
	char *line_n;

	write(1, "Error\n", 6);
	write(1, "\e[1;31m", 7);
	write(1, msg, ft_strlen(msg));
	if (n != -1)
	{	
		line_n = ft_itoa(n);
		write(1, "\n at line ", 10);
		write(1, line_n, ft_strlen(line_n));
	}
	write(1, "\n\e[0m", 5);
	exit(FAILURE);
}

void	exit_failure(t_rt *rt)
{
	free_all(rt);
	perror("Error\n");
	write(1, "\e[1;31mExiting, there was an error.\n\e[0m", 40);
	exit(FAILURE);
}

void	free_all(t_rt *rt)
{
	free_cameras(rt->scene->cameras);
	free_objects(rt->scene->objects);
	free_lights(rt->scene->lights);
	// free and clear window
}

void	exit_free_all(t_scene *scene)
{
	free_cameras(scene->cameras);
	free_objects(scene->objects);
	free_lights(scene->lights);
	(void)scene;
	exit(0);
}