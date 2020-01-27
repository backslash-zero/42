/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 18:53:20 by cmeunier          #+#    #+#             */
/*   Updated: 2020/01/27 21:07:19 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	VECTORS_H
# define VECTORS_H

//double		abs(double nb);

t_point	add_vec(t_point vec1, t_point vec2);
t_point	sub_vec(t_point vec1, t_point vec2);
t_point	mult_point(t_point vec1, t_point vec2);
t_point	div_vec(t_point vec1, t_point vec2);
t_point	add_vec_d(t_point vec1, double val);
t_point	sub_vec_d(t_point vec1, double val);
t_point	mult_point_d(t_point vec1, double val);
t_point	div_vec_d(t_point vec1, double val);
t_point create_vec(double x, double y, double z);
double	prod_scal(t_point vec1, t_point vec2);
double norm_vec(t_point vec);

#endif