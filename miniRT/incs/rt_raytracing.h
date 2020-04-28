/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_raytracing.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:13:01 by cmeunier          #+#    #+#             */
/*   Updated: 2020/04/28 15:16:08 by cmeunier         ###   ########.fr       */
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

t_vec			normal_sphere(t_ray *ray, t_sphere *s);
void			intersect_ray_sphere(t_ray *ray, t_sphere *sphere);
void			intersect_ray_plane(t_ray *ray, t_plane *plane);
void			intersect_ray_square(t_ray *ray, t_square *square);
void			intersect_ray_square_2(t_ray *ray, t_square *square);
void			intersect_ray_triangle(t_ray *ray, t_triangle *triangle);
void			intersect_ray_triangle_2(t_ray *ray, t_triangle *triangle);
void			intersect_ray_cy_2(t_ray *r, t_cylinder *cy, t_vec d, t_vec a);
void			intersect_ray_cylinder(t_ray *ray, t_cylinder *cylinder);
void			intersection(t_ray *ray, t_scene *scene);
void			intersect_object(t_ray *ray, t_objects *tmp);
void			fill_img(t_scene *scene, t_mlx *mlx);
int				trace_ray(t_ray *ray, t_scene *scene);
t_vec			normal_sphere(t_ray *ray, t_sphere *sphere);
t_vec			normal_triangle(t_triangle *triangle);
t_vec			normal_plane(t_plane *plane);
t_vec			normal_cylinder(t_ray *ray, t_cylinder *cylinder);
t_vec			normal_square(t_square *square);
t_vec			normal_calc(t_ray *ray);

#endif
