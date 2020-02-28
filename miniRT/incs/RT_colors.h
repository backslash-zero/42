/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RT_colors.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celestin <celestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 21:48:34 by cmeunier          #+#    #+#             */
/*   Updated: 2020/02/28 17:10:47 by celestin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_COLORS_H
# define RT_COLORS_H

typedef	struct	s_color
{
	double r;
	double g;
	double b;
}				t_color;

int		min_max_color(int value);
int		get_color_integer(int r, int g, int b);
t_color	assign_colors(int r, int g, int b);
t_color	color_by_type_cast(t_objects *object);

#endif