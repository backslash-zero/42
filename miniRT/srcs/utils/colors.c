/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 12:50:57 by cmeunier          #+#    #+#             */
/*   Updated: 2020/02/14 21:56:33 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

int		min_max_color(int value)
{
	if(value < 0)
		return(0);
	if(value > 255)
		return(255);
	return(value);
}

t_color	assign_colors(int r, int g, int b)
{
	t_color color;
	color.r = r;
	color.g = g;
	color.b = b;

	return(color);
}

int		get_color_integer(int r, int g, int b)
{
	int rt;

	rt = 0;
	rt |= min_max_color(r) << 16;
	rt |= min_max_color(g) << 8;
	rt |= min_max_color(b);
	return (rt);
}
