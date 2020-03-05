/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RT_scene.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:34:23 by cmeunier          #+#    #+#             */
/*   Updated: 2020/03/05 12:51:49 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_SCENE_H
# define RT_SCENE_H

typedef	struct	s_camera
{
	t_vec	pos;
	t_vec	rot;
	t_vec	dir_x;
	t_vec	dir_y;
	t_vec	dir_z;
	double	fov;
}				t_camera;

typedef	struct		s_cameras
{
	t_camera			*camera;
	struct s_cameras	*next;
}					t_cameras;

typedef	struct			s_objects
{
	int					id;
	void				*obj;
	struct s_objects	*next;
}						t_objects;

typedef	struct	s_sphere
{
	t_vec	pos;
	double	r;
	t_color	color;
	double	specular;
}				t_sphere;

typedef	struct	s_plane
{
	t_vec	pos;
	t_vec	rot;
	t_vec	normal;
	t_color	color;
	double	specular;
}				t_plane;

typedef	struct	s_square
{
	t_vec	pos;
	t_vec	rot;
	t_color	color;
	t_vec	normal;
	t_vec	point_1;
	t_vec	point_2;
	t_vec	point_3;
	t_vec	point_4;
	double	height;
	double	specular;
}				t_square;

typedef	struct	s_cylinder
{
	t_vec	pos;
	t_vec	pos2;
	t_vec	dir;
	t_vec	rot;
	t_color	color;
	double	diameter;
	double	r;
	double	height;
	double	specular;
}				t_cylinder;

typedef	struct	s_triangle
{
	t_vec	point_1;
	t_vec	point_2;
	t_vec	point_3;
	t_color	color;
	t_vec	normal;
	double	specular;
}				t_triangle;

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

typedef	struct	s_light_vec
{
	t_vec	dir;
	t_color	color;
	double	lum;
}				t_light_vec;

typedef	struct		s_lights
{
	t_point_light	*point_light;
	struct s_lights	*next;
}					t_lights;

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


void	scene_parsing(t_scene *scene);
void	window_parsing(t_scene *scene);
void	viewport_parsing(t_scene *scene);
int		center_x(int x, t_scene *scene);
int		center_y(int y, t_scene *scene);
double	get_vp_x(int x, t_scene *scene);
double	get_vp_y(int y, t_scene *scene);

#endif