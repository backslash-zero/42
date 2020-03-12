/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 16:31:08 by cmeunier          #+#    #+#             */
/*   Updated: 2020/03/12 17:58:27 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minirt.h"

void	skip_nb_spaces(int *i, char *line)
{
	skip_numbers(i, line);
	skip_spaces(i, line);
}

void	skip_spaces(int *i, char *line)
{
	while (line[*i] == ' ' || line[*i] == '\t')
		*i += 1;
}

void	window_parsing(t_rt *rt, char *line, int n)
{
	int i;

	i = 1;
	skip_spaces(&i, line);
	if ((rt->scene->window_width = ft_atoi_double(&line[i])) < 0)
		parsing_err(rt, "Window width cannot be negative.", n);
	skip_numbers(&i, line);
	skip_spaces(&i, line);
	if ((rt->scene->window_height = ft_atoi_double(&line[i])) < 0)
		parsing_err(rt, "Window height cannot be negative.", n);
	if (rt->scene->window_width >= MAX_WINDOW_WIDTH)
		rt->scene->window_width = MAX_WINDOW_WIDTH;
	if (rt->scene->window_height >= MAX_WINDOW_HEIGHT)
		rt->scene->window_height = MAX_WINDOW_HEIGHT;
}

void	viewport_parsing(t_scene *scene)
{
	double	aspect_ratio;

	aspect_ratio = scene->window_width / scene->window_height;
	scene->viewport_d = VIEWPORT_D;
	scene->viewport_height = tan(rad(scene->active_camera->fov / 2))
								* scene->viewport_d * 2;
	scene->viewport_width = aspect_ratio * scene->viewport_height;
}
