/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_lights.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 23:44:00 by cmeunier          #+#    #+#             */
/*   Updated: 2020/03/06 14:45:26 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

void	ambient_light_parsing(t_scene *scene, const char *line)
{
	int i;
	i++;

	skip_spaces(&i, line);
	if(scene->ambient_light.lum = ft_atoi(&line[i]) < 0)
		exit(0); // check lum negative
	skip_spaces(&i, line);
	scene->ambient_light.color = get_color(&i, line);
}

void	point_light_parsing(t_lights **lights, const char *line)
{
	int				i;
	t_point_light	*point_light;
	i++;
	if(!(point_light = malloc(sizeof(t_point_light))))
		exit(0); // MALLOC PROBLEM
	skip_spaces(&i, line);
	point_light->pos = get_vec(&i, line);
	skip_spaces(&i, line);
	if(point_light->lum = ft_atoi(&line[i]) < 0)
		exit(0); // check lum negative
	skip_spaces(&i, line);
	point_light->color = get_color(&i, line);
	add_back_light(lights, point_light);
}

void	add_back_light(t_lights **start, void *point_light)
{
	t_lights *ptr;
	t_lights *new;
	
	new = NULL;

	//initialise light
	if(!(new = (malloc(sizeof(t_lights)))))
		return ;
	new->point_light = point_light;
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
