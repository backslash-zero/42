/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RT_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 16:38:55 by cmeunier          #+#    #+#             */
/*   Updated: 2020/03/11 17:54:32 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H

# define SUCCESS 0
# define FAILURE -1

void	free_lights(t_lights *lights);
void	free_objects(t_objects *objects);
void	free_cameras(t_cameras *cameras);
void	exit_success(t_scene *scene);
void	parsing_err(t_rt *rt, char *msg, int n);
void	exit_failure(t_rt *rt);
void	free_all(t_rt *rt);

#endif