/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 16:31:08 by cmeunier          #+#    #+#             */
/*   Updated: 2020/02/14 22:09:02 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

void	ambient_light_parsing(t_scene *scene)
{
	scene->ambient_light.color = assign_colors(255, 255, 255);
	scene->ambient_light.lum = 0.5;
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

void	calc_camera_dir(t_camera *camera)
{
	camera->dir_x.x = 1;
	camera->dir_x.y = 0;
	camera->dir_x.z = 0;
	camera->dir_y.x = 0;
	camera->dir_y.y = 1;
	camera->dir_y.z = 0;
	camera->dir_z.x = 0;
	camera->dir_z.y = 0;
	camera->dir_z.z = 1;

	//x_rotation(&camera->dir_x, rot_to_deg(camera->rot.x));
	x_rotation(&camera->dir_y, rad(rot_to_deg(camera->rot.x)));
	x_rotation(&camera->dir_z, rad(rot_to_deg(camera->rot.x)));
	y_rotation(&camera->dir_x, rad(rot_to_deg(camera->rot.y)));
	// //y_rotation(&camera->dir_y, rot_to_deg(camera->rot.y));
	y_rotation(&camera->dir_z, rad(rot_to_deg(camera->rot.y)));
	z_rotation(&camera->dir_x, rad(rot_to_deg(camera->rot.z)));
	z_rotation(&camera->dir_y, rad(rot_to_deg(camera->rot.z)));
	//z_rotation(&camera->dir_z, rot_to_deg(camera->rot.z));
}

void	camera_parsing(t_camera *camera)
{
	// get position vector from parsing
	camera->pos.x = 0;
	camera->pos.y = 0;
	camera->pos.z = 0;

	// get position direction vector from parsing
	camera->rot.x = 0;
	camera->rot.y = 0;
	camera->rot.z = 0;

	// calculate direction vector from rotation vectors
	calc_camera_dir(camera);
	camera->fov = FOV;
}

void	scene_parsing(t_scene *scene, t_camera *camera)
{
	window_parsing(scene);
	camera_parsing(camera);
	viewport_parsing(scene, camera);
	scene->objects = NULL;
	object_parsing(&scene->objects);
	ambient_light_parsing(scene);
}
