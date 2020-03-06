/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RT_parsing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 16:17:44 by cmeunier          #+#    #+#             */
/*   Updated: 2020/03/06 14:07:42 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_PARSING_H
# define RT_PARSING_H

void	scene_parsing(t_scene *scene);
void	viewport_parsing(t_scene *scene);
void	object_parsing(t_objects **objects);
void	add_back_obj(t_objects **start, void *obj, int id);
void	calc_camera_dir(t_camera *camera);
void	add_back_cameras(t_cameras **start, void *camera);
void	loopcameras(t_cameras **start);
void	add_back_light(t_lights **start, void *point_light);
void	add_square_points(t_square *square_0);

void	main_parser(t_scene *scene, const char *line);
void	window_parsing(t_scene *scene, const char *line);
void	ambient_light_parsing(t_scene *scene, const char *line);
void	point_light_parsing(t_lights **lights, const char *line);
void	camera_parsing(t_cameras **cameras, const char *line);

int		p_test_window(const char *line);
int		p_test_ambient_light(const char *line);
int		p_test_point_light(const char *line);
int		p_test_triangle(const char *line);
int		p_test_cylinder(const char *line);
int		p_test_square(const char *line);
int		p_test_plane(const char *line);
int		p_test_sphere(const char *line);
int		p_test_camera(const char *line);

int		check_parsing_tracker(t_scene *scene);
void	init_parsing_tracker(t_scene *scene);

void	skip_spaces(int *i, char *line);
int		skip_comma(int *i, char *line);
t_color	get_color(int *i, char *line);
t_vec		get_vec(int *i, char *line);

#endif