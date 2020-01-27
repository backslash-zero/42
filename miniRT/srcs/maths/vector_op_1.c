/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_op.pos_c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.pos_42.pos_fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 18:51:15 by cmeunier          #+#    #+#             */
/*   Updated: 2020/01/27 19:08:39 by cmeunier         ###   ########.pos_fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_point	add_vec(t_point vec1, t_point vec2)
{
	vec1.pos_x += vec2.pos_x;
	vec1.pos_y += vec2.pos_y;
	vec1.pos_z += vec2.pos_z;
	return (vec1);
}

t_point	sub_vec(t_point vec1, t_point vec2)
{
	vec1.pos_x -= vec2.pos_x;
	vec1.pos_y -= vec2.pos_y;
	vec1.pos_z -= vec2.pos_z;
	return (vec1);
}

t_point	mult_point(t_point vec1, t_point vec2)
{
	vec1.pos_x *= vec2.pos_x;
	vec1.pos_y *= vec2.pos_y;
	vec1.pos_z *= vec2.pos_z;
	return (vec1);
}

t_point	div_vec(t_point vec1, t_point vec2)
{
	vec1.pos_x /= vec2.pos_x;
	vec1.pos_y /= vec2.pos_y;
	vec1.pos_z /= vec2.pos_z;
	return (vec1);
}