/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RT_scene.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celestin <celestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:34:23 by cmeunier          #+#    #+#             */
/*   Updated: 2020/02/28 17:36:57 by celestin         ###   ########.fr       */
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
	t_color	color;
	double	specular;
}				t_plane;

typedef	struct	s_square
{
	t_vec	pos;
	t_vec	rot;
	t_color	color;
	double	height;
	double	specular;
}				t_square;

typedef	struct	s_cylinder
{
	t_vec	pos;
	t_vec	rot;
	t_color	color;
	double	diameter;
	double	height;
	double	specular;
}				t_cylinder;

typedef	struct	s_triangle
{
	t_vec	point_1;
	t_vec	point_2;
	t_vec	point_3;
	t_color	color;
	double	specular;
}				s_triangle;

void	scene_parsing(t_scene *scene);
void	window_parsing(t_scene *scene);
void	viewport_parsing(t_scene *scene);
int		center_x(int x, t_scene *scene);
int		center_y(int y, t_scene *scene);
double	get_vp_x(int x, t_scene *scene);
double	get_vp_y(int y, t_scene *scene);

#endif