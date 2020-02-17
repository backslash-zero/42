/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 16:31:08 by cmeunier          #+#    #+#             */
/*   Updated: 2020/02/17 20:02:05 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

void	window_parsing(t_scene *scene)
{
	scene->window_width = WINDOW_WIDTH;
	scene->window_height = WINDOW_HEIGHT;
}

void	viewport_parsing(t_scene *scene)
{
	double	aspect_ratio;

	aspect_ratio = scene->window_width / scene->window_height;
	scene->viewport_d = VIEWPORT_D;
	scene->viewport_height = tan(rad(scene->active_camera->fov / 2)) * scene->viewport_d * 2;
	scene->viewport_width = aspect_ratio * scene->viewport_height;
}

void	scene_parsing(t_scene *scene)
{
	scene->objects = NULL;
	scene->cameras = NULL;

	window_parsing(scene);
	camera_parsing(&scene->cameras);
	scene->active_camera = scene->cameras->camera;
	// edit cameras
	viewport_parsing(scene);
	object_parsing(&scene->objects);
	ambient_light_parsing(scene);
	point_light_parsing(&scene->lights);
}
