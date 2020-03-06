/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_cameras.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 19:03:20 by cmeunier          #+#    #+#             */
/*   Updated: 2020/03/06 20:47:29 by cmeunier         ###   ########.fr       */
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
	rotation_calc(&camera->dir_x, camera->rot);
	rotation_calc(&camera->dir_y, camera->rot);
	rotation_calc(&camera->dir_z, camera->rot);
}

void	loopcameras(t_cameras **start)
{
	t_cameras *ptr;
	ptr = *start;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = *start;

}

void	camera_parsing(t_cameras **cameras, char *line)
{
	t_camera	*camera;
	int			i;

	i = 1;
	if(!(camera = (malloc(sizeof(t_camera)))))
		exit(0); // MALLOC PROBLEM
	skip_spaces(&i, line);
	camera->pos = get_vec(&i, line);
	skip_spaces(&i, line);
	camera->rot = get_vec(&i, line);
	skip_spaces(&i, line);
	if((camera->fov = ft_atoi_double(&line[i])) < 0 ||
		camera->fov > 180)
	{	
		exit(0); // wrong FOV
	}
	calc_camera_dir(camera);
	add_back_cameras(cameras, camera);
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
