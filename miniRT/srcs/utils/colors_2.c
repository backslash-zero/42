/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 15:32:28 by cmeunier          #+#    #+#             */
/*   Updated: 2020/04/28 20:21:07 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minirt.h"

t_color	color_by_type_cast_util_1(t_objects *object)
{
	t_sphere	*tmp_sphere;
	t_triangle	*tmp_triangle;
	t_cylinder	*tmp_cylinder;

	if (object->id == (int)'s')
	{
		tmp_sphere = (t_sphere *)object->obj;
		return (tmp_sphere->color);
	}
	if (object->id == (int)'c')
	{
		tmp_cylinder = (t_cylinder *)object->obj;
		return (tmp_cylinder->color);
	}
	if (object->id == (int)'t')
	{
		tmp_triangle = (t_triangle *)object->obj;
		return (tmp_triangle->color);
	}
	return (assign_colors(255, 255, 255));
}

t_color	color_by_type_cast_util_2(t_objects *object)
{
	t_plane		*tmp_plane;
	t_square	*tmp_square;

	if (object->id == (int)'p')
	{
		tmp_plane = (t_plane *)object->obj;
		return (tmp_plane->color);
	}
	if (object->id == (int)'S')
	{
		tmp_square = (t_square *)object->obj;
		return (tmp_square->color);
	}
	return (assign_colors(255, 255, 255));
}

t_color	color_by_type_cast(t_objects *object)
{
	if ((object->id == (int)'s')
		|| (object->id == (int)'c')
		|| (object->id == (int)'t'))
		return (color_by_type_cast_util_1(object));
	if ((object->id == (int)'S')
		|| (object->id == (int)'p'))
		return (color_by_type_cast_util_2(object));
	return (assign_colors(255, 255, 255));
}
