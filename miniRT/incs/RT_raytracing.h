/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RT_raytracing.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celestin <celestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:13:01 by cmeunier          #+#    #+#             */
/*   Updated: 2020/02/28 17:22:54 by celestin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_RAYTRACING_H
# define RT_RAYTRACING_H

typedef	struct	s_inter
{
	double t1;
	double t2;
}				t_inter;

typedef	struct	s_ray
{
	t_vec		dir;
	t_vec		origin;
	t_vec		point;
	t_vec		normal;
	t_inter		inter;
	double		closest_t;
	t_objects	*closest_object;
	t_color		color;
}				t_ray;

void	intersect_ray_sphere(t_ray *ray, t_sphere *sphere);
void	intersection(t_ray *ray, t_scene *scene);
void	intersect_object(t_ray *ray, t_objects *tmp);
t_vec	normal_calc(t_ray *ray);

#endif