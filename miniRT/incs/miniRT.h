/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:25:48 by cmeunier          #+#    #+#             */
/*   Updated: 2020/01/29 18:18:46 by cmeunier         ###   ########.fr       */
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
	double	fov;
}				t_camera;

typedef	struct	s_ray
{
	double t1;
	double t2;
}				t_ray;

typedef	struct	s_sphere
{
	t_point	pos;
	double	r;
	int 	color;
}				t_sphere;

typedef	struct	s_scene
{
	double	window_width;
	double	window_height;
	double	viewport_width;
	double	viewport_height;
	double	viewport_d;
}				t_scene;

#define BACKGROUND_COLOR	16777216
#define WINDOW_WIDTH	800
#define WINDOW_HEIGHT 	600
#define VIEWPORT_D		1
#define FOV				60

// Self-made headers
# include "RT_scene.h"
# include "vectors.h"
# include "RT_parsing.h"
# include "error.h"
# include "get_next_line.h"
# include "RT_utils.h"

#endif