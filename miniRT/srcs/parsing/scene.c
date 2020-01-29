/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 16:31:08 by cmeunier          #+#    #+#             */
/*   Updated: 2020/01/29 16:57:19 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	scene_parsing(t_scene *scene, t_camera *camera)
{
	window_parsing(scene);
	viewport_parsing(scene, camera);
}

void	window_parsing(t_scene *scene)
{
	scene->window_width = WINDOW_WIDTH;
	scene->window_height = VIEWPORT_HEIGHT;
}

void	viewport_parsing(t_scene *scene, t_camera *camera)
{
	double	windowratio;

	windowratio = scene->window_width / scene->window_height;
	scene->viewport_d = 1;
	scene->viewport_height = tan(camera->fov / 2) * scene->viewport_d * 2;
	scene->viewport_width = windowratio * scene->viewport_height;
}

void	object_parsing(t_scene *scene)
{

}

void	