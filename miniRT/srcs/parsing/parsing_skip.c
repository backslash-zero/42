/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_skip.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 17:23:09 by cmeunier          #+#    #+#             */
/*   Updated: 2020/03/12 17:30:31 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minirt.h"

t_vec	get_vec(t_rt *rt, int *i, char *line, int n)
{
	t_vec vec;

	vec.x = ft_atoi_double(&line[*i]);
	skip_numbers(i, line);
	if (!skip_comma(i, line))
		parsing_err(rt, "Problem with vector, missing comma", n);
	vec.y = ft_atoi_double(&line[*i]);
	skip_numbers(i, line);
	if (!skip_comma(i, line))
		parsing_err(rt, "Problem with vector, missing comma", n);
	vec.z = ft_atoi_double(&line[*i]);
	skip_numbers(i, line);
	return (vec);
}

int		skip_comma(int *i, char *line)
{
	if (line[*i] == ',')
		*i += 1;
	else
		return (0);
	return (1);
}

t_color	get_color(t_rt *rt, int *i, char *line, int n)
{
	t_color color;

	if ((color.r = ft_atoi_double(&line[*i])) < 0 || color.r > 255)
		parsing_err(rt, "R color value invalid", n);
	skip_numbers(i, line);
	if (!skip_comma(i, line))
		parsing_err(rt, "Bad formatting, missing comma", n);
	if ((color.g = ft_atoi_double(&line[*i])) < 0 || color.g > 255)
		parsing_err(rt, "G color value invalid", n);
	skip_numbers(i, line);
	if (!skip_comma(i, line))
		parsing_err(rt, "Bad formatting, missing comma.", n);
	if ((color.b = ft_atoi_double(&line[*i])) < 0 || color.b > 255)
		parsing_err(rt, "B color value invalid", n);
	skip_numbers(i, line);
	return (color);
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
	while (line[*i] == '.' || is_plusminus(line[*i]) || is_digit(line[*i]))
		*i += 1;
}
