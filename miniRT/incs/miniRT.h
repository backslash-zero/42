/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:25:48 by cmeunier          #+#    #+#             */
/*   Updated: 2020/01/27 20:00:23 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT_H
# define MINI_RT_H

# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

// MinilibX
# include <mlx.h>

// Self-made headers
# include "vectors.h"

#define BACKGROUND_COLOR	16777216

typedef	struct	s_camera
{
	double pos_x;
	double pos_y;
	double pos_z;
}				t_camera;

typedef	struct	s_point
{
	double pos_x;
	double pos_y;
	double pos_z;
}				t_point;

typedef	struct	s_ray
{
	double t1;
	double t2;
}				t_ray;

typedef	struct	s_sphere
{
	double pos_x;
	double pos_y;
	double pos_z;
	double r;
	int color;
}				t_sphere;

#define VIEWPORT_WIDTH	1
#define VIEWPORT_HEIGHT 1

#define VIEWPORT_D		1

#define WINDOW_WIDTH	800
#define WINDOW_HEIGHT 	800


// Personal Headers
# include "RT_parsing.h"
# include "error.h"
# include "get_next_line.h"
# include "utils.h"
# include "scene.h"

#endif