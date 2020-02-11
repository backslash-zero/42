/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 16:31:08 by cmeunier          #+#    #+#             */
/*   Updated: 2020/02/11 17:11:13 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

void	scene_parsing(t_scene *scene, t_camera *camera)
{
	window_parsing(scene);
	camera_parsing(camera);
	viewport_parsing(scene, camera);
	scene->objects = NULL;
	object_parsing(&scene->objects);
}

void	window_parsing(t_scene *scene)
{
	scene->window_width = WINDOW_WIDTH;
	scene->window_height = WINDOW_HEIGHT;
}

void	viewport_parsing(t_scene *scene, t_camera *camera)
{
	double	aspect_ratio;

	aspect_ratio = scene->window_width / scene->window_height;
	scene->viewport_d = VIEWPORT_D;
	scene->viewport_height = tan(rad(camera->fov / 2)) * scene->viewport_d * 2;
	scene->viewport_width = aspect_ratio * scene->viewport_height;
}

void	camera_parsing(t_camera *camera)
{
	camera->pos.x = 0;
	camera->pos.y = 0;
	camera->pos.z = 0;
	camera->rot.x = 0;
	camera->rot.y = 0;
	camera->rot.z = 0;
	camera->fov = FOV;
}