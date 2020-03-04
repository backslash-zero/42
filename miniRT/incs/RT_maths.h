/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RT_maths.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 18:53:20 by cmeunier          #+#    #+#             */
/*   Updated: 2020/03/04 13:28:15 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	RT_MATHS_H
# define RT_MATHS_H

void	init_vec(t_vec *vec, double x, double y, double z);
t_vec	add_vec(t_vec vec1, t_vec vec2);
t_vec	sub_vec(t_vec vec1, t_vec vec2);
t_vec	mult_point(t_vec vec1, t_vec vec2);
t_vec	div_vec(t_vec vec1, t_vec vec2);
t_vec	add_vec_d(t_vec vec1, double val);
t_vec	sub_vec_d(t_vec vec1, double val);
t_vec	mult_point_d(t_vec vec1, double val);
t_vec	div_vec_d(t_vec vec1, double val);
t_vec	create_vec(double x, double y, double z);
double	prod_scal(t_vec vec1, t_vec vec2);
double	norm_vec(t_vec vec);
t_vec	normalized(t_vec vec);
t_vec	cross_vec(t_vec a, t_vec b);
double	rad(double nb);
void	x_rotation(t_vec *dir, double angle);
void	y_rotation(t_vec *dir, double angle);
void	z_rotation(t_vec *dir, double angle);
double	rot_to_deg(double rotation);
void	rotation_calc(t_vec *vec, t_vec rot);

#endif