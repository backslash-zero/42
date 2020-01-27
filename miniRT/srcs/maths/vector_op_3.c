/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_op_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 19:23:51 by cmeunier          #+#    #+#             */
/*   Updated: 2020/01/27 21:22:25 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/* double	abs(double nb)
{
	if(nb < 0)
		return(-nb);
	return(nb);
} */

double	prod_scal(t_point vec1, t_point vec2)
{
	return (vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z);
}

t_point create_vec(double x, double y, double z)
{
	t_point vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return(vec);
}

double norm_vec(t_point vec)
{
	return (sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z));
}
