/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:25:41 by cmeunier          #+#    #+#             */
/*   Updated: 2020/02/17 20:00:19 by cmeunier         ###   ########.fr       */
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

void intersect_ray_sphere(t_camera *camera, t_ray *ray, t_sphere *sphere)
{
	t_vec oc;
	
	oc = sub_vec(camera->pos, sphere->pos);
	double k1 = prod_scal(ray->dir, ray->dir);
    double k2 = 2 * prod_scal(oc, ray->dir);
    double k3 = prod_scal(oc, oc) - (sphere->r * sphere->r);

    double discriminant = (k2 * k2) - (4 * k1 * k3);
    if(discriminant < 0)
	{
		ray->inter.t1 = __DBL_MAX__;
		ray->inter.t2 = __DBL_MAX__;
	}
	else
	{
		ray->inter.t1 = (-k2 + sqrt(discriminant)) / (2 * k1);
		ray->inter.t2 = (-k2 - sqrt(discriminant)) / (2 * k1);
	}
}

void	intersect_object(t_scene *scene, t_ray *ray, t_objects *tmp)
{
	if(tmp->id == (int)'s')
		intersect_ray_sphere(scene->active_camera, ray, tmp->obj);
	/*
	if(tmp->id == (int)'c')
	if(tmp->id == (int)'t')
	if(tmp->id == (int)'p')
	if(tmp->id == (int)'s')
	if(tmp->id == (int)'s')
	*/
}

t_color		color_by_type_cast(t_objects *object)
{
	t_sphere *tmp;

	if(object->id == (int)'s')
	{
		tmp = (t_sphere *)object->obj;
		return(tmp->color);
	}
	return(assign_colors(255, 255, 255));
}

void	ambient_lighting(t_color *color, t_scene *scene)
{
	color->r = scene->ambient_light.lum * color->r * (scene->ambient_light.color.r / 255);
	color->g = scene->ambient_light.lum * color->g * (scene->ambient_light.color.g / 255);
	color->b = scene->ambient_light.lum * color->b * (scene->ambient_light.color.b / 255);
}

int		trace_ray(t_ray *ray, t_scene *scene){
	t_color		color;
	double		closest_t;
	double		min_z;
	double		max_z;
	t_objects	*tmp;
	t_objects	*closest_object;

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
		intersect_object(scene, ray, tmp);
		if(ray->inter.t1 > min_z && ray->inter.t1 < max_z && ray->inter.t1 < closest_t)
		{
			closest_t = ray->inter.t1;
			closest_object = tmp;
		}
		if(ray->inter.t2 > min_z && ray->inter.t2 < max_z && ray->inter.t2 < closest_t)
		{
			closest_t = ray->inter.t2;
			closest_object = tmp;
		}
		// put white if no sphere interesection was found.
		if(closest_object != NULL)
			color = color_by_type_cast(closest_object);
		tmp = tmp->next;
	}
	if(closest_object == NULL)
		return(get_color_integer(255, 255, 255));
	ambient_lighting(&color, scene);
	return(get_color_integer(color.r, color.g, color.b));
}

void	ft_init_mlx(t_mlx *mlx, t_scene *scene)
{
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, scene->window_width, scene->window_height, "MiniRT");
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, scene->window_width, scene->window_height);
	mlx->img_data = (int*)mlx_get_data_addr(mlx->img_ptr, &mlx->bpp, &mlx->size_line, &mlx->endian);
}

void	init_vec(t_vec *vec)
{
	vec->x = 0;
	vec->y = 0;
	vec->z = 0;
}

void	fill_img(t_scene *scene, t_mlx *mlx)
{
	int 	x;
	int 	y;
	int		len;
	t_ray	ray;

	len = mlx->size_line / 4;
	y = -1;
	while(++y < scene->window_height)
	{
		x = -1;
		while(++x < scene->window_width)
		{	
			init_vec(&ray.dir);
			ray.dir = add_vec(ray.dir, scene->active_camera->dir_z);
			ray.dir = add_vec(ray.dir, mult_point_d(scene->active_camera->dir_x, get_vp_x(center_x(x, scene), scene)));
			ray.dir = add_vec(ray.dir, mult_point_d(scene->active_camera->dir_y, get_vp_y(center_y(y, scene), scene)));
			mlx->img_data[y * len + x] = trace_ray(&ray, scene);
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
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	mlx_key_hook(mlx->win_ptr, ft_key, mlx);
	mlx_loop(mlx->mlx_ptr);
}

int		main(int ac, char **av)
{
	(void)av;
	t_scene				scene;
	t_mlx				mlx;
	int					stop = 1;

	if(ac == 2)
	{
		scene_parsing(&scene);
		ft_init_mlx(&mlx, &scene);	
		if(stop)
		{
			stop = 0;
			printf("\nscene.window_width: 				%f\n", scene.window_width);
			printf("\nscene.window_height: 				%f\n", scene.window_height);
			printf("\nscene.viewport_d: 			%f\n", scene.viewport_d);
			printf("\nscene.viewport_height: 			%f\n", scene.viewport_height);
			printf("\nscene.viewport_width: 			%f\n", scene.viewport_width);
			printf("\ncamera.fov: 					%f\n", scene.active_camera->fov);
			printf("\ncamera.pos.x: 				%f\n", scene.active_camera->pos.x);
			printf("\ncamera.pos.y: 				%f\n", scene.active_camera->pos.y);
			printf("\ncamera.pos.z: 				%f\n", scene.active_camera->pos.z);
			printf("\ncamera.dir_x.x: 				%f\n", scene.active_camera->dir_x.x);
			printf("\ncamera.dir_y.x: 				%f\n", scene.active_camera->dir_y.x);
			printf("\ncamera.dir_z.x: 				%f\n", scene.active_camera->dir_z.x);
			printf("\ncamera.dir_x.y: 				%f\n", scene.active_camera->dir_x.y);
			printf("\ncamera.dir_y.y: 				%f\n", scene.active_camera->dir_y.y);
			printf("\ncamera.dir_z.y: 				%f\n", scene.active_camera->dir_z.y);
			printf("\ncamera.dir_x.z: 				%f\n", scene.active_camera->dir_x.z);
			printf("\ncamera.dir_y.z: 				%f\n", scene.active_camera->dir_y.z);
			printf("\ncamera.dir_z.z: 				%f\n", scene.active_camera->dir_z.z);
		}
		fill_img(&scene, &mlx);
		start_window(&mlx);
		// we need to FREE objects when exiting program
	}
	else
	{
		// error number of arguments parsed
	}
	return(0);
}
