/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tracker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 12:11:22 by cmeunier          #+#    #+#             */
/*   Updated: 2020/03/06 17:35:01 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

void	init_parsing_tracker(t_scene *scene)
{
	scene->objects = NULL;
	scene->cameras = NULL;
	scene->lights = NULL;
	scene->objects = NULL;
	scene->tracker.camera = 0;
	scene->tracker.window = 0;
	scene->tracker.ambient_light = 0;
}

int		check_parsing_tracker(t_scene *scene)
{
	if(scene->tracker.camera &&
		scene->tracker.window &&
		scene->tracker.ambient_light)
		return (1);
	else
		return (0);
}
