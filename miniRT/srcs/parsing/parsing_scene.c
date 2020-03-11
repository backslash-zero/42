/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 16:31:08 by cmeunier          #+#    #+#             */
/*   Updated: 2020/03/11 18:58:12 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

t_vec		get_vec(int *i, char *line)
{
	t_vec vec;
	
	vec.x = ft_atoi_double(&line[*i]);
	skip_numbers(i, line);
	if(!skip_comma(i, line))
		exit(0); // bad formatting : missing comma
	vec.y = ft_atoi_double(&line[*i]);
	skip_numbers(i, line);
	if(!skip_comma(i, line))
		exit(0); // bad formatting : missing comma
	vec.z = ft_atoi_double(&line[*i]);
	skip_numbers(i, line);
	return(vec);
}

int		skip_comma(int *i, char *line)
{
	if(line[*i] == ',')
		*i += 1;
	else
		return (0);
	return (1);
}

t_color		get_color(t_rt *rt, int *i, char *line, int n)
{
	t_color color;
	
	if((color.r = ft_atoi_double(&line[*i])) < 0 || color.r > 255)
		parsing_err(rt, "RGB color value invalid", n);
	skip_numbers(i, line);
	if(!skip_comma(i, line))
		parsing_err(rt, "Bad formatting, missing comma", n);
	if((color.g = ft_atoi_double(&line[*i])) < 0 || color.g > 255)
		parsing_err(rt, "RGB color value invalid", n);
	skip_numbers(i, line);
	if(!skip_comma(i, line))
		parsing_err(rt, "Bad formatting, missing comma", n);
	if((color.b = ft_atoi_double(&line[*i])) < 0 || color.b > 255)
		parsing_err(rt, "RGB color value invalid", n);
	skip_numbers(i, line);
	//if color > 255 or < 0 exit
	return(color);
}

int		string_empty(char *line)
{
	if (line[0] == '\0' || line[0] == '\n' || line[0] == '#')
		return (1);
	else
		return (0);	
}

void	skip_numbers(int *i, char *line)
{
	while(line[*i] == '.' || is_plusminus(line[*i]) || is_digit(line[*i]))
		*i += 1;
}
void	skip_spaces(int *i, char *line)
{
	while(line[*i] == ' ' || line[*i] == '\t')
		*i += 1;
}

void	window_parsing(t_scene *scene, char *line)
{
	int i;
	
	i = 1;
	skip_spaces(&i, line);
	if((scene->window_width = ft_atoi_double(&line[i])) < 0)
		exit_free_all(scene);; // check resolution negative
	skip_numbers(&i, line);
	skip_spaces(&i, line);
	if((scene->window_height = ft_atoi_double(&line[i])) < 0)
		exit_free_all(scene);; // check resolution negative
	if(scene->window_width >= MAX_WINDOW_WIDTH)
		scene->window_width = MAX_WINDOW_WIDTH;
	if(scene->window_height >= MAX_WINDOW_HEIGHT)
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
