/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_op_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 19:23:51 by cmeunier          #+#    #+#             */
/*   Updated: 2020/01/27 19:48:03 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	abs(double nb)
{
	if(nb < 0)
		return(-nb);
	return(nb);
}

double	prod_scal(t_point vec1, t_point vec2)
{
	return (vec1.pos_x * vec2.pos_x + vec1.pos_y * vec2.pos_y + vec1.pos_z * vec2.pos_z);
}

t_point create_vec(double x, double y, double z)
{
	t_point vec;

	vec.pos_x = x;
	vec.pos_y = y;
	vec.pos_z = z;
	return (vec);
}

double norm_vec(t_point vec)
{
	return (sqrt(vec.pos_x * vec.pos_x + vec.pos_y * vec.pos_y + vec.pos_z * vec.pos_z));
}
