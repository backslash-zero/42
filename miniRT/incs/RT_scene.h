/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RT_scene.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:34:23 by cmeunier          #+#    #+#             */
/*   Updated: 2020/02/17 20:00:54 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_SCENE_H
# define RT_SCENE_H

void	scene_parsing(t_scene *scene);
void	window_parsing(t_scene *scene);
void	viewport_parsing(t_scene *scene);

#endif