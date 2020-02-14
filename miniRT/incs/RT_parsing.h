/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RT_parsing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 16:17:44 by cmeunier          #+#    #+#             */
/*   Updated: 2020/02/14 22:14:37 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_PARSING_H
# define RT_PARSING_H

void	scene_parsing(t_scene *scene, t_camera *camera);
void	ambient_light_parsing(t_scene *scene);
void	window_parsing(t_scene *scene);
void	viewport_parsing(t_scene *scene, t_camera *camera);
void	object_parsing(t_objects **objects);
void	add_back_obj(t_objects **start, void *obj, int id);

#endif