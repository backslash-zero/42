/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 12:50:57 by cmeunier          #+#    #+#             */
/*   Updated: 2020/03/04 17:52:27 by cmeunier         ###   ########.fr       */
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

t_color		color_by_type_cast(t_objects *object)
{
	t_sphere	*tmp_sphere;
	t_plane		*tmp_plane;
	t_square	*tmp_square;
	t_triangle	*tmp_triangle;
	t_cylinder	*tmp_cylinder;

	if(object->id == (int)'s')
	{
		tmp_sphere = (t_sphere *)object->obj;
		return(tmp_sphere->color);
	}
	if(object->id == (int)'c')
	{
		tmp_cylinder = (t_cylinder *)object->obj;
		return(tmp_cylinder->color);
	}
	if(object->id == (int)'t')
	{
		tmp_triangle = (t_triangle *)object->obj;
		return(tmp_triangle->color);
	}
	if(object->id == (int)'p')
	{
		tmp_plane = (t_plane *)object->obj;
		return(tmp_plane->color);
	}
	if(object->id == (int)'S')
	{
		tmp_square = (t_square *)object->obj;
		return(tmp_square->color);
	}
	return(assign_colors(255, 255, 255));
}
