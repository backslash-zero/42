/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:25:48 by cmeunier          #+#    #+#             */
/*   Updated: 2020/01/27 21:20:24 by cmeunier         ###   ########.fr       */
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

#define BACKGROUND_COLOR	16777216

typedef	struct	s_point
{
	double x;
	double y;
	double z;
}				t_point;

typedef	struct	s_camera
{
	t_point pos;
	t_point rot;
}				t_camera;

typedef	struct	s_ray
{
	double t1;
	double t2;
}				t_ray;

typedef	struct	s_sphere
{
	t_point pos;
	double r;
	int color;
}				t_sphere;

#define VIEWPORT_WIDTH	1
#define VIEWPORT_HEIGHT 1

#define VIEWPORT_D		1

#define WINDOW_WIDTH	800
#define WINDOW_HEIGHT 	800


// Self-made headers
# include "vectors.h"
# include "RT_parsing.h"
# include "error.h"
# include "get_next_line.h"
# include "utils.h"
# include "scene.h"

#endif