/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 16:31:08 by cmeunier          #+#    #+#             */
/*   Updated: 2020/02/13 21:45:58 by cmeunier         ###   ########.fr       */
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

double	rot_to_deg(double rotation)
{
	return(rotation * 360);
}

void	x_rotation(t_vec *dir, double angle)
{
	dir->x = (1 * dir->x) + (0 * dir->y) + (0 * dir->z);
	dir->y = (0 * dir->x) + (cos(angle) * dir->y) + (-sin(angle) * dir->z);
	dir->z = (0 * dir->x) + (sin(angle)* dir->y) + (cos(angle) * dir->z);
}

void	y_rotation(t_vec *dir, double angle)
{
	dir->x = (cos(angle) * dir->x) + (0 * dir->y) + (sin(angle) * dir->z);
	dir->y = (0 * dir->x) + (1 * dir->y) + (0 * dir->z);
	dir->z = (-sin(angle) * dir->x) + (0 * dir->y) + (cos(angle) * dir->z);
}
void	z_rotation(t_vec *dir, double angle)
{
	dir->x = (cos(angle) * dir->x) + (-sin(angle) * dir->y) + (0 * dir->z);
	dir->y = (sin(angle) * dir->x) + (cos(angle) * dir->y) + (0 * dir->z);
	dir->z = (0 * dir->x) + (0 * dir->y) + (1 * dir->z);
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
	x_rotation(&camera->dir_y, rad(rot_to_deg(camera->rot.x)));
	x_rotation(&camera->dir_z, rad(rot_to_deg(camera->rot.x)));
	y_rotation(&camera->dir_x, rad(rot_to_deg(camera->rot.y)));
	y_rotation(&camera->dir_z, rad(rot_to_deg(camera->rot.y)));
	z_rotation(&camera->dir_y, rad(rot_to_deg(camera->rot.z)));
	z_rotation(&camera->dir_x, rad(rot_to_deg(camera->rot.z)));
}

void	camera_parsing(t_camera *camera)
{
	// get position vector from parsing
	camera->pos.x = 0;
	camera->pos.y = 0;
	camera->pos.z = -10;

	// get position direction vector from parsing
	camera->rot.x = 0;
	camera->rot.y = 0;
	camera->rot.z = 0;

	// calculate direction vector from rotation vectors
	calc_camera_dir(camera);
	camera->fov = FOV;
}