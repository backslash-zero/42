/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RT_scene.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:34:23 by cmeunier          #+#    #+#             */
/*   Updated: 2020/02/14 23:55:33 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_SCENE_H
# define RT_SCENE_H

void	scene_parsing(t_scene *scene, t_camera *camera);
void	window_parsing(t_scene *scene);
void	viewport_parsing(t_scene *scene, t_camera *camera);
void	camera_parsing(t_camera *camera);
void	ambient_light_parsing(t_scene *scene);
void	calc_camera_dir(t_camera *camera);
void	point_light_parsing(t_lights **lights);
void	add_back_light(t_lights **start, void *point_light);

#endif