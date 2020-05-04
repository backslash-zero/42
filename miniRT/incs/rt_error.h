/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 16:38:55 by cmeunier          #+#    #+#             */
/*   Updated: 2020/05/01 16:23:28 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_ERROR_H
# define RT_ERROR_H

# define SUCCESS 0
# define FAILURE -1

int		quit_window(t_rt *rt, int code);
void	free_lights(t_lights *lights);
void	free_objects(t_objects *objects);
void	free_cameras(t_cameras *cameras);
void	exit_success(t_rt *rt);
void	parsing_err(t_rt *rt, char *msg, int n);
void	exit_failure(t_rt *rt);
void	exit_openfail(void);
void	exit_formatfail(void);
void	free_all(t_rt *rt);

#endif
