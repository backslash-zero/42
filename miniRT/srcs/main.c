/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:25:41 by cmeunier          #+#    #+#             */
/*   Updated: 2020/02/14 15:16:11 by cmeunier         ###   ########.fr       */
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

void intersect_inter_sphere(t_inter *inter, t_camera *camera, t_vec *ray, t_sphere *sphere)
{
	t_vec oc;
	
	oc = sub_vec(camera->pos, sphere->pos);
	double k1 = prod_scal(*ray, *ray);
    double k2 = 2 * prod_scal(oc, *ray);
    double k3 = prod_scal(oc, oc) - (sphere->r * sphere->r);

    double discriminant = (k2 * k2) - (4 * k1 * k3);
    if(discriminant < 0)
	{
		inter->t1 = __DBL_MAX__;
		inter->t2 = __DBL_MAX__;
	}
	else
	{
    	inter->t1 = (-k2 + sqrt(discriminant)) / (2 * k1);
    	inter->t2 = (-k2 - sqrt(discriminant)) / (2 * k1);
	}
}

void	intersect_object(t_inter *inter, t_camera *camera, t_vec *ray, t_objects *tmp)
{
	if(tmp->id == (int)'s')
		intersect_inter_sphere(inter, camera, ray, tmp->obj);
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

int		trace_inter(t_camera *camera, t_vec *ray, t_scene *scene){
	int			color;
	double		closest_t;
	double		min_z;
	double		max_z;
	t_objects	*tmp;
	t_objects	*closest_object;
	t_inter		inter;

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
		intersect_object(&inter, camera, ray, tmp);
		if(inter.t1 > min_z && inter.t1 < max_z && inter.t1 < closest_t)
		{
			closest_t = inter.t1;
			closest_object = tmp;
		}
		if(inter.t2 > min_z && inter.t2 < max_z && inter.t2 < closest_t)
		{
			closest_t = inter.t2;
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

void	rotate_vp(t_vec *ray, t_scene *scene, t_camera *camera, double x, double y)
{
	*ray = add_vec(*ray, camera->dir_z);
	*ray = add_vec(*ray, div_vec_d(mult_point_d(mult_point_d(camera->dir_x, (x - (scene->window_width / 2)) / scene->viewport_width), scene->viewport_width), scene->window_width));
	*ray = add_vec(*ray, div_vec_d(mult_point_d(mult_point_d(camera->dir_y, (- y + (scene->window_height / 2)) / scene->viewport_height), scene->viewport_height), scene->window_height));
}

void	init_vec(t_vec *vec)
{
	vec->x = 0;
	vec->y = 0;
	vec->z = 0;
}

void	fill_img_2(t_scene *scene, t_mlx *mlx, t_camera *camera)
{
	int 	x;
	int 	y;
	int		len;
	t_vec	ray;

	len = mlx->size_line / 4;
	y = -1;
	while(++y < scene->window_height)
	{
		x = -1;
		while(++x < scene->window_width)
		{	
			init_vec(&ray);
			rotate_vp(&ray, scene, camera, x, y);
			mlx->img_data[y * len + x] = trace_inter(camera, &ray, scene);
		}
	}
}

void	fill_img_3(t_scene *scene, t_mlx *mlx, t_camera *camera)
{
	int 	x;
	int 	y;
	int		len;
	t_vec	ray;

	len = mlx->size_line / 4;
	y = -1;
	while(++y < scene->window_height)
	{
		x = -1;
		while(++x < scene->window_width)
		{	
			init_vec(&ray);
			ray = add_vec(ray, camera->dir_z);
			ray = add_vec(ray, mult_point_d(camera->dir_x, get_vp_x(center_x(x, scene), scene)));
			ray = add_vec(ray, mult_point_d(camera->dir_y, get_vp_y(center_y(y, scene), scene)));
			mlx->img_data[y * len + x] = trace_inter(camera, &ray, scene);
		}
	}
}

void	fill_img(t_scene *scene, t_mlx *mlx, t_camera *camera)
{
	int 	x;
	int 	y;
	int		len;
	t_vec	ray;

	len = mlx->size_line / 4;
	y = -1;
	while(++y < scene->window_height)
	{
		x = -1;
		while(++x < scene->window_width)
		{
			//printf("\n x: %d	y: %d\n", x, y);
			ray.x = get_vp_x(center_x(x, scene), scene);
			ray.y = get_vp_y(center_y(y, scene), scene);
			ray.z = scene->viewport_d;
			mlx->img_data[y * len + x] = trace_inter(camera, &ray, scene);
		}
	}
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
			printf("\ncamera.dir_x.x: 				%f\n", camera.dir_x.x);
			printf("\ncamera.dir_y.x: 				%f\n", camera.dir_y.x);
			printf("\ncamera.dir_z.x: 				%f\n", camera.dir_z.x);
			printf("\ncamera.dir_x.y: 				%f\n", camera.dir_x.y);
			printf("\ncamera.dir_y.y: 				%f\n", camera.dir_y.y);
			printf("\ncamera.dir_z.y: 				%f\n", camera.dir_z.y);
			printf("\ncamera.dir_x.z: 				%f\n", camera.dir_x.z);
			printf("\ncamera.dir_y.z: 				%f\n", camera.dir_y.z);
			printf("\ncamera.dir_z.z: 				%f\n", camera.dir_z.z);
		}
		fill_img_3(&scene, &mlx, &camera);
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
