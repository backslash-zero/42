/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:25:41 by cmeunier          #+#    #+#             */
/*   Updated: 2020/02/11 19:58:39 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int		center_x(int x, t_scene *scene)
{
	x = - (scene->window_width / 2) + x;
	return(x);
}

int		center_y(int y, t_scene *scene)
{
	y = (scene->window_height / 2) - y;
	return(y);
}

double get_vp_x(int x, t_scene *scene)
{
	double vp_x;

	vp_x = (double)x * scene->viewport_width / scene->window_width;
	return(vp_x);
}

double get_vp_y(int y, t_scene *scene)
{
	double vp_y;

	vp_y = (double)y * scene->viewport_height / scene->window_height;
	return(vp_y);
}

void intersect_ray_sphere(t_ray *ray, t_camera *camera, t_vec *viewport_point, t_sphere *sphere)
{
	t_vec oc;
	
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

void	intersect_object(t_ray *ray, t_camera *camera, t_vec *viewport_point, t_objects *tmp)
{
	if(tmp->id == (int)'s')
		intersect_ray_sphere(ray, camera, viewport_point, tmp->obj);
	/*
	if(tmp->id == (int)'c')
	if(tmp->id == (int)'t')
	if(tmp->id == (int)'p')
	if(tmp->id == (int)'s')
	if(tmp->id == (int)'s')
	*/
}

int		color_by_type_cast(t_objects *object)
{
	t_sphere *tmp;

	if(object->id == (int)'s')
	{
		tmp = (t_sphere *)object->obj;
		return(tmp->color);
	}
	return(0);
}

int		trace_ray(t_camera *camera, t_vec *viewport_point, t_scene *scene){
	int			color;
	double		closest_t;
	double		min_z;
	double		max_z;
	t_objects	*tmp;
	t_objects	*closest_object;
	t_ray		ray;

	min_z = scene->viewport_d;
	max_z = __DBL_MAX__;
	tmp = scene->objects;

	//int count = 1;
	closest_object = NULL;
	closest_t = max_z;
	while(tmp)
	{
		//printf("count: %d\n", count);
		//count++;
		intersect_object(&ray, camera, viewport_point, tmp);
		if(ray.t1 > min_z && ray.t1 < max_z && ray.t1 < closest_t)
		{
			closest_t = ray.t1;
			closest_object = tmp;
		}
		if(ray.t2 > min_z && ray.t2 < max_z && ray.t2 < closest_t)
		{
			closest_t = ray.t2;
			closest_object = tmp;
		}
		// put white if no sphere interesection was found.
		if(closest_object == NULL)
			color = get_color_integer(255, 255, 255);
		else
			color = color_by_type_cast(closest_object);
		tmp = tmp->next;
	}
	return(color);
}

void	ft_init_mlx(t_mlx *mlx, t_scene *scene)
{
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, scene->window_width, scene->window_height, "MiniRT");
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, scene->window_width, scene->window_height);
	mlx->img_data = (int*)mlx_get_data_addr(mlx->img_ptr, &mlx->bpp, &mlx->size_line, &mlx->endian);
}

void	fill_img(t_scene *scene, t_mlx *mlx, t_camera *camera)
{
	int 	x;
	int 	y;
	int 	color;
	int		len;
	t_vec	viewport_point;
	
	(void)color;

	len = mlx->size_line / 4;
	y = -1;
	while(++y < scene->window_height)
	{
		x = -1;
		while(++x < scene->window_width)
		{
			//printf("\n x: %d	y: %d\n", x, y);
			viewport_point.x = get_vp_x(center_x(x, scene), scene);
			viewport_point.y = get_vp_y(center_y(y, scene), scene);
			viewport_point.z = scene->viewport_d;
			mlx->img_data[y * len + x] = trace_ray(camera, &viewport_point, scene);
		}
	} 
	/* 
	x = - scene->window_width / 2;
	y = - scene->window_height / 2;
	while(x < scene->window_width / 2)
	{
		while(y <= scene->window_height / 2)
		{
			// translate canvas x and y to viewport
			viewport_point.x = get_vp_x(x, scene);
			viewport_point.y = get_vp_y(y, scene);
			viewport_point.z = scene->viewport_d;
			//color = trace_ray(camera, &viewport_point, VIEWPORT_D, __DBL_MAX__);
			mlx->img_data[center_x(x,scene) + (center_y(y, scene) * mlx->size_line / 4)] = get_color_integer(255, 0, 255);
			//mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, center_x(x, scene), center_y(y, scene), color);
			y++;
		}
		y = - scene->window_height / 2;
		x++;
	} 
	*/
}

int		ft_key(int key,t_mlx *mlx)
{
		(void)mlx;
		if(key == 53)
			exit(0);
		else
			return(0);
}

void	start_window(t_mlx *mlx)
{
	//mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	/*
			OR MAYBE instead of 0,0 in mlx_put_image_to_window
			int x = - scene.window_width / 2;
			int y = - scene.window_height / 2;
	*/
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	mlx_key_hook(mlx->win_ptr, ft_key, mlx);
	mlx_loop(mlx->mlx_ptr);
}

int		main(int ac, char **av)
{
	(void)av;
	t_camera 			camera;
	t_scene				scene;
	t_mlx				mlx;
	int					stop = 1;

	if(ac == 2)
	{
		scene_parsing(&scene, &camera);
		ft_init_mlx(&mlx, &scene);
	// PARSING TESTS;

		if(stop)
		{
			stop = 0;
			printf("\nscene.window_width: 				%f\n", scene.window_width);
			printf("\nscene.window_height: 				%f\n", scene.window_height);
			printf("\nscene.viewport_d: 			%f\n", scene.viewport_d);
			printf("\nscene.viewport_height: 			%f\n", scene.viewport_height);
			printf("\nscene.viewport_width: 			%f\n", scene.viewport_width);
			printf("\ncamera.fov: 				%f\n", camera.fov);
			printf("\ncamera.pos.x: 				%f\n", camera.pos.x);
			printf("\ncamera.pos.y: 				%f\n", camera.pos.y);
			printf("\ncamera.pos.z: 				%f\n", camera.pos.z);
		}
		fill_img(&scene, &mlx, &camera);
		// mlx_hook && mlx_hook_loop?
		start_window(&mlx);
		// we need to FREE objects when exiting program
	}
	else
	{
		// error number of arguments parsed
	}
	return(0);
}
