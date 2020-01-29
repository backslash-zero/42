/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:25:41 by cmeunier          #+#    #+#             */
/*   Updated: 2020/01/29 15:25:53 by cmeunier         ###   ########.fr       */
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

	vp_x = (double)x * VIEWPORT_WIDTH / WINDOW_WIDTH;
	return(vp_x);
}

double get_vp_y(int y)
{
	double vp_y;

	vp_y = (double)y * VIEWPORT_HEIGHT / WINDOW_HEIGHT;
	return(vp_y);
}

void intersect_ray_sphere(t_ray *ray, t_camera *camera, t_point *viewport_point, t_sphere *sphere)
{
	t_point oc;
	
	oc = sub_vec(camera->pos, sphere->pos);
	double k1 = prod_scal(*viewport_point, *viewport_point);
    double k2 = 2 * prod_scal(oc, *viewport_point);
    double k3 = prod_scal(oc, oc) - (sphere->r * sphere->r);

    double discriminant = (k2 * k2) - (4 * k1 * k3);
    if(discriminant < 0)
	{
		ray->t1 = __DBL_MAX__;
		ray->t2 = __DBL_MAX__;
	}
	else
	{
    	ray->t1 = (-k2 + sqrt(discriminant)) / (2 * k1);
    	ray->t2 = (-k2 - sqrt(discriminant)) / (2 * k1);
	}
}

int		trace_ray(t_camera *camera, t_point *viewport_point, double min_z, double max_z){
	int			color;
	double		closest_t;
	t_sphere	*closest_sphere;
	t_sphere 	sphere_0;
	t_ray		ray;

	// this should be included in a loop to enable every sphere
	sphere_0.pos.x = 1;
	sphere_0.pos.y = 1;
	sphere_0.pos.z = 10;
	sphere_0.r = 2;
	sphere_0.color = get_color_integer(0, 3, 104);
	closest_t = max_z;
	closest_sphere = NULL;
	intersect_ray_sphere(&ray, camera, viewport_point, &sphere_0);
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
	if(closest_sphere == NULL)
		color = get_color_integer(255, 255, 255);
	else
		color = closest_sphere->color;
	return(color);
}

int		main(int ac, char **av)
{
	(void)av;
	t_camera 			camera;
	t_point				viewport_point;
	int 				color;
	camera.pos.x = 0;
	camera.pos.y = 0;
	camera.pos.z = 0;
	camera.fov = 60;
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
				viewport_point.x = get_vp_x(x);
				viewport_point.y = get_vp_y(y);
				viewport_point.z = VIEWPORT_D;
				color = trace_ray(&camera, &viewport_point, VIEWPORT_D, __DBL_MAX__);
				//color = get_color_integer(255, 255, 255);
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
