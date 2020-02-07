/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 18:53:20 by cmeunier          #+#    #+#             */
/*   Updated: 2020/02/07 17:35:11 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	VECTORS_H
# define VECTORS_H

//double		abs(double nb);

t_vec	add_vec(t_vec vec1, t_vec vec2);
t_vec	sub_vec(t_vec vec1, t_vec vec2);
t_vec	mult_point(t_vec vec1, t_vec vec2);
t_vec	div_vec(t_vec vec1, t_vec vec2);
t_vec	add_vec_d(t_vec vec1, double val);
t_vec	sub_vec_d(t_vec vec1, double val);
t_vec	mult_point_d(t_vec vec1, double val);
t_vec	div_vec_d(t_vec vec1, double val);
t_vec create_vec(double x, double y, double z);
double	prod_scal(t_vec vec1, t_vec vec2);
double norm_vec(t_vec vec);

#endif