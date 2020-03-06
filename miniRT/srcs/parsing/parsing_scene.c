/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 16:31:08 by cmeunier          #+#    #+#             */
/*   Updated: 2020/03/06 14:01:56 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

t_color		get_color(int *i, char *line)
{
	t_color color;
	
	if(color.r = ft_atoi(line[*i]) < 0)
		exit(0); // check negative number
	if(!skip_comma(*i, line))
		exit(0); // bad formatting : missing comma
	if(color.g = ft_atoi(line[*i]) < 0)
		exit(0); // check negative number
	if(!skip_comma(*i, line))
		exit(0); // bad formatting : missing comma
	if(color.b = ft_atoi(line[*i]) < 0)
		exit(0); // check negative number
	return(color);
}

void	skip_spaces(int *i, char *line)
{
	while(line[*i] == ' ' || line[*i] == '\t')
		*i++;
}

int		skip_comma(int *i, char *line)
{
	if(line[*i] == ',')
		*i++;
	else
		return (0);
	return (1);
	
}

void	window_parsing(t_scene *scene, const char *line)
{
	int i;
	i++;
	skip_spaces(&i, line);
	if(scene->window_width = ft_atoi(&line[i]) < 0)
		exit(0); // check resolution negative
	skip_spaces(&i, line);
	if(scene->window_height = ft_atoi(&line[i]) < 0)
		exit(0); // check resolution negative
	if(scene->window_width <= MAX_WINDOW_WIDTH)
		scene->window_width = WINDOW_WIDTH;
	else
		scene->window_width = MAX_WINDOW_WIDTH;
	if(scene->window_height <= MAX_WINDOW_HEIGHT)
		scene->window_height = WINDOW_HEIGHT;
	else
		scene->window_height = MAX_WINDOW_HEIGHT;
}

void	viewport_parsing(t_scene *scene)
{
	double	aspect_ratio;

	aspect_ratio = scene->window_width / scene->window_height;
	scene->viewport_d = VIEWPORT_D;
	scene->viewport_height = tan(rad(scene->active_camera->fov / 2)) * scene->viewport_d * 2;
	scene->viewport_width = aspect_ratio * scene->viewport_height;
}
