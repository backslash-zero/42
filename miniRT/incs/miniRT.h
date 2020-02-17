/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:25:48 by cmeunier          #+#    #+#             */
/*   Updated: 2020/02/17 19:52:08 by cmeunier         ###   ########.fr       */
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

typedef	struct	s_camera
{
	t_vec	pos;
	t_vec	rot;
	t_vec	dir_x;
	t_vec	dir_y;
	t_vec	dir_z;
	double	fov;
}				t_camera;

typedef	struct	s_inter
{
	double t1;
	double t2;
}				t_inter;

typedef	struct	s_ray
{
	t_vec	dir;
	t_inter	inter;
}				t_ray;

typedef	struct	s_ambient_light
{
	double	lum;
	t_color	color;
}				t_ambient_light;

typedef	struct	s_point_light
{
	t_vec	pos;
	double	lum;
	t_color	color;
}				t_point_light;

typedef	struct	s_sphere
{
	t_vec	pos;
	double	r;
	t_color	color;
}				t_sphere;

typedef	struct			s_objects
{
	int					id;
	void				*obj;
	struct s_objects	*next;
}						t_objects;

typedef	struct		s_lights
{
	t_point_light	*point_light;
	struct s_lights	*next;
}					t_lights;

typedef	struct		s_cameras
{
	t_camera			*camera;
	struct s_cameras	*next;
}					t_cameras;

typedef	struct		s_scene
{
	double			window_width;
	double			window_height;
	double			viewport_width;
	double			viewport_height;
	double			viewport_d;
	t_objects		*objects;
	t_cameras		*cameras;
	t_camera		*active_camera;
	t_lights		*lights;
	t_ambient_light	ambient_light;
}					t_scene;

#define WINDOW_WIDTH	800
#define WINDOW_HEIGHT 	600
#define VIEWPORT_D		1
#define FOV				60

// Self-made headers
# include "RT_mlx.h"
# include "RT_scene.h"
# include "RT_colors.h"
# include "RT_maths.h"
# include "RT_utils.h"
# include "error.h"
# include "get_next_line.h"
# include "RT_parsing.h"

#endif