/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 13:04:12 by cmeunier          #+#    #+#             */
/*   Updated: 2020/03/09 15:45:16 by cmeunier         ###   ########.fr       */
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

void	exit_free_all(t_scene *scene)
{
	free_cameras(scene->cameras);
	free_objects(scene->objects);
	free_lights(scene->lights);
	(void)scene;
	exit(0);
}