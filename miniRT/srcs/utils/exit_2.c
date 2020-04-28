/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 16:55:47 by cmeunier          #+#    #+#             */
/*   Updated: 2020/04/28 20:22:13 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minirt.h"

void	free_lights(t_lights *lights)
{
	t_lights *tmp;

	while (lights)
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

	while (objects)
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
	while (cameras)
	{
		tmp = cameras;
		cameras = cameras->next;
		free(tmp->camera);
		free(tmp);
		if (cameras == first)
			cameras = NULL;
	}
}
