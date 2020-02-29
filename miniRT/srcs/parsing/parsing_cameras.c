/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_cameras.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 19:03:20 by cmeunier          #+#    #+#             */
/*   Updated: 2020/02/29 19:57:07 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

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
	z_rotation(&camera->dir_x, rad(rot_to_deg(camera->rot.z)));
	z_rotation(&camera->dir_y, rad(rot_to_deg(camera->rot.z)));
}

void	loopcameras(t_cameras **start)
{
	t_cameras *ptr;
	ptr = *start;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = *start;

}

void	camera_parsing(t_cameras **cameras)
{
	*cameras = NULL;
	t_camera *camera_0;
	t_camera *camera_1;
	t_camera *camera_2;

	if(!(camera_0 = (malloc(sizeof(t_camera)))))
		return ;
	camera_0->pos.x = 0;
	camera_0->pos.y = 5;
	camera_0->pos.z = -10;
	camera_0->rot.x = 0.1;
	camera_0->rot.y = 0;
	camera_0->rot.z = 0;
	calc_camera_dir(camera_0);
	camera_0->fov = FOV;
	add_back_cameras(cameras, camera_0);

	if(!(camera_1 = (malloc(sizeof(t_camera)))))
		return ;
	camera_1->pos.x = 0;
	camera_1->pos.y = 0;
	camera_1->pos.z = 30;
	camera_1->rot.x = 0;
	camera_1->rot.y = -1;
	camera_1->rot.z = 0;
	calc_camera_dir(camera_1);
	camera_1->fov = FOV;
	add_back_cameras(cameras, camera_1);
	
	if(!(camera_2 = (malloc(sizeof(t_camera)))))
		return ;
	camera_2->pos.x = 15;
	camera_2->pos.y = 10;
	camera_2->pos.z = -50;
	camera_2->rot.x = 0.1;
	camera_2->rot.y = -0.5;
	camera_2->rot.z = 0;
	calc_camera_dir(camera_2);
	camera_2->fov = FOV;
	add_back_cameras(cameras, camera_2);
	loopcameras(cameras);
}

void	add_back_cameras(t_cameras **start, void *camera)
{
	t_cameras *ptr;
	t_cameras *new;
	
	new = NULL;

	//initialise light
	if(!(new = (malloc(sizeof(t_cameras)))))
		return ;
	new->camera = camera;
	new->next = NULL;
	//adding light to the linked list
	if(!*start)
	{	
		*start = new;
		return ;
	}
	ptr = *start;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = new;
}
