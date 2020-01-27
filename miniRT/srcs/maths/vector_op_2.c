/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_op_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 19:23:34 by cmeunier          #+#    #+#             */
/*   Updated: 2020/01/27 21:22:12 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_point	add_vec_d(t_point vec1, double val)
{
	vec1.x += val;
	vec1.y += val;
	vec1.z += val;
	return (vec1);
}

t_point	sub_vec_d(t_point vec1, double val)
{
	vec1.x -= val;
	vec1.y -= val;
	vec1.z -= val;
	return (vec1);
}

t_point	mult_point_d(t_point vec1, double val)
{
	vec1.x *= val;
	vec1.y *= val;
	vec1.z *= val;
	return (vec1);
}

t_point	div_vec_d(t_point vec1, double val)
{
	vec1.x /= val;
	vec1.y /= val;
	vec1.z /= val;
	return (vec1);
}