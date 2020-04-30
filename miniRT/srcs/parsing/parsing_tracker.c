/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tracker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 12:11:22 by cmeunier          #+#    #+#             */
/*   Updated: 2020/04/30 19:37:06 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minirt.h"

int		check_extension(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	if (i < 3)
		return (0);
	if ((str[i - 3] == '.') &&
		(str[i - 2] == 'r') &&
		(str[i - 1] == 't'))
		return (1);
	return (0);
}

void	init_parsing_tracker(t_scene *scene)
{
	scene->objects = NULL;
	scene->cameras = NULL;
	scene->lights = NULL;
	scene->invert = 0;
	scene->tracker.camera = 0;
	scene->tracker.window = 0;
	scene->tracker.ambient_light = 0;
}

int		check_parsing_tracker(t_scene *scene)
{
	if (scene->tracker.camera &&
		scene->tracker.window &&
		scene->tracker.ambient_light)
		return (1);
	else
		return (0);
}
