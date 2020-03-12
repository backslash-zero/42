/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_test_objects.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 18:06:04 by cmeunier          #+#    #+#             */
/*   Updated: 2020/03/12 18:13:07 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minirt.h"

int	p_test_sphere(char *line)
{
	if ((line[0] == 's' && line[1] == 'p'))
		return (1);
	else
		return (0);
}

int	p_test_plane(char *line)
{
	if ((line[0] == 'p' && line[1] == 'l'))
		return (1);
	else
		return (0);
}

int	p_test_square(char *line)
{
	if ((line[0] == 's' && line[1] == 'q'))
		return (1);
	else
		return (0);
}

int	p_test_cylinder(char *line)
{
	if ((line[0] == 'c' && line[1] == 'y'))
		return (1);
	else
		return (0);
}

int	p_test_triangle(char *line)
{
	if ((line[0] == 't' && line[1] == 'r'))
		return (1);
	else
		return (0);
}
