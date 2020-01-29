/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 16:31:08 by cmeunier          #+#    #+#             */
/*   Updated: 2020/01/29 17:18:42 by cmeunier         ###   ########.fr       */
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
	scene->window_height = WINDOW_HEIGHT;
}

void	viewport_parsing(t_scene *scene, t_camera *camera)
{
	double	aspect_ratio;

	aspect_ratio = scene->window_width / scene->window_height;
	scene->viewport_d = VIEWPORT_D;
	scene->viewport_height = tan(camera->fov / 2) * scene->viewport_d * 2;
	scene->viewport_width = aspect_ratio * scene->viewport_height;
}
