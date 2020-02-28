/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RT_lights.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celestin <celestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 13:46:40 by cmeunier          #+#    #+#             */
/*   Updated: 2020/02/28 17:22:30 by celestin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_LIGHTS_H
# define RT_LIGHTS_H

typedef	struct	s_ambient_light
{
	double	lum;
	t_color	color;
}				t_ambient_light;

typedef	struct	s_point_light
{
	t_vec	pos;
	double	lum;
	t_color	color;
}				t_point_light;

typedef	struct	s_light_vec
{
	t_vec	dir;
	t_color	color;
	double	lum;
}				t_light_vec;

typedef	struct		s_lights
{
	t_point_light	*point_light;
	struct s_lights	*next;
}					t_lights;

void	process_light(t_scene *scene, t_ray *ray);
void	point_light(t_scene *scene, t_ray *ray);
void	light_calc(t_color *color, double lum, t_color light_color);
void	add_light(t_color *color, double new_i, t_color point_light_color);
void	convert_light_ray(t_ray *ray, t_ray *light_ray, t_light_vec *light_vec);
void	ambient_light(t_scene *scene, t_ray *ray);
void	ambient_lighting(t_color *color, t_scene *scene);
void	specular_light(t_ray *ray, double specular, t_light_vec *light_vec );
void	specular_light_processing(t_ray *ray, t_light_vec *light_vec);
int		shadow_intersection(t_ray *light_ray, t_scene *scene, t_light_vec *light_vec);

#endif