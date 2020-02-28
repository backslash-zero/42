/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RT_raytracing.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:13:01 by cmeunier          #+#    #+#             */
/*   Updated: 2020/02/28 14:20:41 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_RAYTRACING_H
# define RT_RAYTRACING_H

void	intersect_ray_sphere(t_ray *ray, t_sphere *sphere);
void	intersection(t_ray *ray, t_scene *scene);
void	intersect_object(t_ray *ray, t_objects *tmp);
t_vec	normal_calc(t_ray *ray);

#endif