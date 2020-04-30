/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_colors.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 21:48:34 by cmeunier          #+#    #+#             */
/*   Updated: 2020/04/28 21:08:48 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_COLORS_H
# define RT_COLORS_H

int		min_max_color(int value);
int		get_color_integer(int r, int g, int b);
t_color	assign_colors(int r, int g, int b);
t_color color_by_type_cast_util_1(t_objects *object);
t_color color_by_type_cast_util_2(t_objects *object);
t_color	color_by_type_cast(t_objects *object);
void	invert_color(t_color *color);

#endif
