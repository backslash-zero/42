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

t_vec	add_vec(t_vec vec1, t_vec vec2)
{
	vec1.x += vec2.x;
	vec1.y += vec2.y;
	vec1.z += vec2.z;
	return (vec1);
}

t_vec	sub_vec(t_vec vec1, t_vec vec2)
{
	vec1.x -= vec2.x;
	vec1.y -= vec2.y;
	vec1.z -= vec2.z;
	return (vec1);
}

t_vec	mult_point(t_vec vec1, t_vec vec2)
{
	vec1.x *= vec2.x;
	vec1.y *= vec2.y;
	vec1.z *= vec2.z;
	return (vec1);
}

t_vec	div_vec(t_vec vec1, t_vec vec2)
{
	vec1.x /= vec2.x;
	vec1.y /= vec2.y;
	vec1.z /= vec2.z;
	return (vec1);
}
