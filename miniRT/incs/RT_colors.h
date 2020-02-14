/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RT_colors.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 21:48:34 by cmeunier          #+#    #+#             */
/*   Updated: 2020/02/14 21:56:16 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_COLORS_H
# define RT_COLORS_H

int		min_max_color(int value);
int		get_color_integer(int r, int g, int b);
t_color	assign_colors(int r, int g, int b);

#endif