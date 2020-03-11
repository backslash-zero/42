/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RT_parsing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 16:17:44 by cmeunier          #+#    #+#             */
/*   Updated: 2020/03/11 18:55:49 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_PARSING_H
# define RT_PARSING_H

void	scene_parsing(t_rt *rt);
void	viewport_parsing(t_scene *scene);
void	add_back_obj(t_objects **start, void *obj, int id);
void	calc_camera_dir(t_camera *camera);
void	add_back_cameras(t_cameras **start, void *camera);
void	loopcameras(t_cameras **start);
void	add_back_light(t_lights **start, void *point_light);
void	add_square_points(t_square *square_0);

void	main_parser(t_rt *rt, char *line, int n);
void	window_parsing(t_scene *scene, char *line);
void	ambient_light_parsing(t_scene *scene, char *line);
void	point_light_parsing(t_lights **lights, char *line);
void	camera_parsing(t_cameras **cameras, char *line);

void	object_parsing(t_objects **objects);
void	sphere_parsing(t_rt *rt, char *line, int n);
void	plane_parsing(t_rt *rt, char *line, int n);
void	square_parsing(t_rt *rt, char *line, int n);
void	triangle_parsing(t_rt *rt, char *line, int n);
void	cylinder_parsing(t_rt *rt, char *line, int n);

int		p_test_window(t_scene *scene, char *line);
int		p_test_ambient_light(t_scene *scene, char *line);
int		p_test_point_light(char *line);
int		p_test_triangle(char *line);
int		p_test_cylinder(char *line);
int		p_test_square(char *line);
int		p_test_plane(char *line);
int		p_test_sphere(char *line);
int		p_test_camera(t_scene *scene, char *line);

int		check_parsing_tracker(t_scene *scene);
void	init_parsing_tracker(t_scene *scene);

void	skip_spaces(int *i, char *line);
void	skip_numbers(int *i, char *line);
int		string_empty(char *line);
int		skip_comma(int *i, char *line);
t_color	get_color(t_rt *rt, int *i, char *line, int n);
t_vec	get_vec(int *i, char *line);

#endif