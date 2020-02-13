/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_op_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 19:23:51 by cmeunier          #+#    #+#             */
/*   Updated: 2020/02/12 13:07:22 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

double	prod_scal(t_vec vec1, t_vec vec2)
{
	return (vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z);
}

t_vec create_vec(double x, double y, double z)
{
	t_vec vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return(vec);
}

double norm_vec(t_vec vec)
{
	return (sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z));
}

t_vec	normalized(t_vec vec)
{
	return(div_vec_d(vec, norm_vec(vec)));
}

