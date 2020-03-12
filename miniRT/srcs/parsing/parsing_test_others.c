/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_test_others.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 18:10:13 by cmeunier          #+#    #+#             */
/*   Updated: 2020/03/12 18:20:42 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minirt.h"

int		p_test_window(t_rt *rt, char *line, int n)
{
	if (line[0] == 'R')
	{
		if (rt->scene->tracker.window)
			parsing_err(rt, "Resolution assigned more than once", n);
		else
		{
			rt->scene->tracker.window = 1;
			return (1);
		}
	}
	return (0);
}

int		p_test_camera(t_scene *scene, char *line)
{
	if (line[0] == 'c' && line[1] != 'y')
	{
		scene->tracker.camera = 1;
		return (1);
	}
	else
		return (0);
}

int		p_test_point_light(char *line)
{
	if (line[0] == 'l')
	{
		return (1);
	}
	else
		return (0);
}

int		p_test_ambient_light(t_rt *rt, char *line, int n)
{
	if (line[0] == 'A')
	{
		if (rt->scene->tracker.ambient_light)
			parsing_err(rt, "Ambient light assigned more than once", n);
		else
		{
			rt->scene->tracker.ambient_light = 1;
			return (1);
		}
	}
	return (0);
}
