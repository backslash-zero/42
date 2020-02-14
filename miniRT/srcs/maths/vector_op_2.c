/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_op_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 19:23:34 by cmeunier          #+#    #+#             */
/*   Updated: 2020/02/14 15:16:08 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

t_vec	add_vec_d(t_vec vec1, double val)
{
	vec1.x += val;
	vec1.y += val;
	vec1.z += val;
	return (vec1);
}

t_vec	sub_vec_d(t_vec vec1, double val)
{
	vec1.x -= val;
	vec1.y -= val;
	vec1.z -= val;
	return (vec1);
}

t_vec	mult_point_d(t_vec vec1, double val)
{
	vec1.x *= val;
	vec1.y *= val;
	vec1.z *= val;
	return (vec1);
}

t_vec	div_vec_d(t_vec vec1, double val)
{
	vec1.x /= val;
	vec1.y /= val;
	vec1.z /= val;
	return (vec1);
}