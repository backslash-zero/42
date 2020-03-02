/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:25:48 by cmeunier          #+#    #+#             */
/*   Updated: 2020/03/02 14:38:11 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT_H
# define MINI_RT_H

// Standard libraries
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

// MinilibX
# include <mlx.h>

#define MAX_WINDOW_WIDTH	2560
#define MAX_WINDOW_HEIGHT 	1440
#define WINDOW_WIDTH		1200
#define WINDOW_HEIGHT 		800
#define VIEWPORT_D			1
#define FOV					60


typedef	struct	s_color
{
	double r;
	double g;
	double b;
}				t_color;

typedef	struct	s_vec
{
	double x;
	double y;
	double z;
}				t_vec;

// Self-made headers
# include "RT_maths.h"
# include "get_next_line.h"
# include "RT_scene.h"
# include "RT_mlx.h"
# include "RT_utils.h"
# include "error.h"
# include "RT_colors.h"
# include "RT_parsing.h"
# include "RT_raytracing.h"
# include "RT_lights.h"

#endif