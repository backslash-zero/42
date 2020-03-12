/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_objects_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 17:31:36 by cmeunier          #+#    #+#             */
/*   Updated: 2020/03/12 17:33:00 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minirt.h"

void	add_square_points(t_square *square_0)
{
	t_vec	i;
	t_vec	j;

	init_vec(&i, square_0->height / 2, 0, 0);
	init_vec(&j, 0, square_0->height / 2, 0);
	rotation_calc(&i, square_0->rot);
	rotation_calc(&j, square_0->rot);
	square_0->point_1 = add_vec(square_0->pos,
						add_vec(j, mult_point_d(i, -1)));
	square_0->point_2 = add_vec(square_0->pos,
						add_vec(j, i));
	square_0->point_3 = add_vec(square_0->pos,
						add_vec(mult_point_d(j, -1), i));
	square_0->point_4 = add_vec(square_0->pos,
						add_vec(mult_point_d(j, -1), mult_point_d(i, -1)));
}

int		add_back_obj(t_objects **start, void *obj, int id)
{
	t_objects *ptr;
	t_objects *new;

	new = NULL;
	if (!(new = (malloc(sizeof(t_objects)))))
		return (FAILURE);
	new->id = id;
	new->obj = obj;
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
