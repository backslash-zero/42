/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:25:41 by cmeunier          #+#    #+#             */
/*   Updated: 2020/01/27 20:01:04 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int		center_x(int x)
{
	x = (WINDOW_WIDTH / 2) + x;
	return(x);
}

int		center_y(int y)
{
	y = (WINDOW_HEIGHT / 2) - y;
	return(y);
}

int		min_max_color(int value)
{
	if(value < 0)
		return(0);
	if(value > 255)
		return(255);
	return(value);
}

int get_color_integer(int r, int g, int b)
{
	int rt;

	rt = 0;
	rt |= min_max_color(r) << 16;
	rt |= min_max_color(g) << 8;
	rt |= min_max_color(b);
	return (rt);
}

double get_vp_x(int x)
{
	double vp_x;

	vp_x = x * VIEWPORT_WIDTH / WINDOW_WIDTH;
	return(vp_x);
}

double get_vp_y(int y)
{
	double vp_y;

	vp_y = y * VIEWPORT_HEIGHT / WINDOW_HEIGHT;
	return(vp_y);
}

void intersect_ray_sphere(t_ray *ray, t_camera *camera, t_point *viewport_point, t_sphere *sphere)
{
	t_point oc;
	
	oc = sub_vec(camera, sphere);
	double k1 = prod_scal(viewport_point, viewport_point);
    double k2 = 2 * prod_scal(oc, viewport_point);
    double k3 = sub_vec_d(prod_scal(oc, oc), (sphere->r * sphere->r));

    double discriminant = k2*k2 - 4*k1*k3;
    if(discriminant < 0)
	{
		ray->t1 = INFINITY;
		ray->t2 = INFINITY;
	}
	else
	{
    	ray->t1 = (-k2 + sqrt(discriminant)) / (2 * k1);
    	ray->t2 = (-k2 - sqrt(discriminant)) / (2 * k1);
	}
}

int		trace_ray(t_camera *camera, t_point *viewport_point, int min_z, int max_z){
	int			color;
	double		closest_t;
	t_sphere	*closest_sphere;
	t_sphere 	sphere_0;
	t_ray		ray;

	// this should be included in a loop to enable every sphere
	sphere_0.pos_x = 0;
	sphere_0.pos_y = -1;
	sphere_0.pos_z = 3;
	sphere_0.r = 1;
	sphere_0.color = get_color_integer(217, 3, 104);;
	closest_t = max_z;
	closest_sphere = NULL;
	intersect_ray_sphere(&ray, &camera, &viewport_point, &sphere_0);
	if(ray.t1 > min_z && ray.t1 < max_z && ray.t1 < closest_t)
	{
		closest_t = ray.t1;
		closest_sphere = &sphere_0;
	}
	if(ray.t2 > min_z && ray.t2 < max_z && ray.t2 < closest_t)
	{
		closest_t = ray.t2;
		closest_sphere = &sphere_0;
	}
	// put white if no sphere interesection was found.
	if(closest_sphere = NULL)
		color = BACKGROUND_COLOR;
	color = closest_sphere->color;
	return(color);
}

int		main(int ac, char **av)
{
	(void)av;
	t_camera 			camera;
	t_point				viewport_point;
	int 				color;
	camera.pos_x = 0;
	camera.pos_y = 0;
	camera.pos_z = 0;
	if(ac == 2)
	{
		//parsing_scene(av[1]);
		void *win_ptr;
		void *mlx_ptr;

		mlx_ptr = mlx_init();
		win_ptr = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "MiniRT");

		int x = - WINDOW_WIDTH / 2;
		int y = - WINDOW_HEIGHT / 2;
		while(x < WINDOW_WIDTH / 2)
		{
			while(y < WINDOW_HEIGHT / 2)
			{
				// translate canvas x and y to viewport
				viewport_point.pos_x = get_vp_x(x);
				viewport_point.pos_y = get_vp_y(y);
				viewport_point.pos_z = VIEWPORT_D;
				color = trace_ray(&camera, &viewport_point, VIEWPORT_D, INFINITY);
				mlx_pixel_put(mlx_ptr, win_ptr, center_x(x), center_y(y), color);
				y++;
			}
			y = - WINDOW_HEIGHT / 2;
			x++;
		}
		mlx_loop(mlx_ptr);
	}
	else
	{
		// error number of arguments parsed
	}
	return(0);
}
