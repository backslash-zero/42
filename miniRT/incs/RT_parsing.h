/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RT_parsing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celestin <celestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 16:17:44 by cmeunier          #+#    #+#             */
/*   Updated: 2020/02/28 17:23:21 by celestin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_PARSING_H
# define RT_PARSING_H

void	scene_parsing(t_scene *scene);
void	ambient_light_parsing(t_scene *scene);
void	window_parsing(t_scene *scene);
void	viewport_parsing(t_scene *scene);
void	object_parsing(t_objects **objects);
void	add_back_obj(t_objects **start, void *obj, int id);
void	calc_camera_dir(t_camera *camera);
void	camera_parsing(t_cameras **cameras);
void	add_back_cameras(t_cameras **start, void *camera);
void	ambient_light_parsing(t_scene *scene);
void	point_light_parsing(t_lights **lights);
void	add_back_light(t_lights **start, void *point_light);

#endif