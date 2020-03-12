/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_lights.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 23:44:00 by cmeunier          #+#    #+#             */
/*   Updated: 2020/03/12 18:15:36 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minirt.h"

void	ambient_light_parsing(t_rt *rt, char *line, int n)
{
	int i;

	i = 1;
	skip_spaces(&i, line);
	if ((rt->scene->ambient_light.lum = ft_atoi_double(&line[i])) < 0)
		parsing_err(rt, "Luminosity cannot be negative.", n);
	skip_numbers(&i, line);
	skip_spaces(&i, line);
	rt->scene->ambient_light.color = get_color(rt, &i, line, n);
}

void	point_light_parsing(t_rt *rt, char *line, int n)
{
	int				i;
	t_point_light	*point_light;

	i = 1;
	if (!(point_light = malloc(sizeof(t_point_light))))
		exit_failure(rt);
	skip_spaces(&i, line);
	point_light->pos = get_vec(rt, &i, line, n);
	skip_spaces(&i, line);
	if ((point_light->lum = ft_atoi_double(&line[i])) < 0)
		parsing_err(rt, "Luminosity cannot be negative.", n);
	skip_numbers(&i, line);
	skip_spaces(&i, line);
	point_light->color = get_color(rt, &i, line, n);
	if (add_back_light(&rt->scene->lights, point_light) == FAILURE)
		exit_failure(rt);
}

int		add_back_light(t_lights **start, void *point_light)
{
	t_lights *ptr;
	t_lights *new;

	new = NULL;
	if (!(new = (malloc(sizeof(t_lights)))))
		return (FAILURE);
	new->point_light = point_light;
	new->next = NULL;
	if (!*start)
	{
		*start = new;
		return (SUCCESS);
	}
	ptr = *start;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = new;
	return (SUCCESS);
}
