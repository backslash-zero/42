/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:25:41 by cmeunier          #+#    #+#             */
/*   Updated: 2020/02/25 21:36:47 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

void	init_vec(t_vec *vec)
{
	vec->x = 0;
	vec->y = 0;
	vec->z = 0;
}

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
	/*
	if(object->id == (int)'c')
	if(object->id == (int)'t')
	if(object->id == (int)'p')
	if(object->id == (int)'s')
	if(object->id == (int)'s')
	*/
	return(assign_colors(255, 255, 255));
}

void	ambient_lighting(t_color *color, t_scene *scene)
{
	color->r = scene->ambient_light.lum * color->r * (scene->ambient_light.color.r / 255);
	color->g = scene->ambient_light.lum * color->g * (scene->ambient_light.color.g / 255);
	color->b = scene->ambient_light.lum * color->b * (scene->ambient_light.color.b / 255);
}

void	light_calc(t_color *color, double lum, t_color light_color)
{
	color->r = lum * color->r * (light_color.r / 255);
	color->g = lum * color->g * (light_color.g / 255);
	color->b = lum * color->b * (light_color.b / 255);
}

void	point_light(t_scene *scene, t_vec point, t_vec normal, t_color *color)
{
	t_vec		light_vec;
	t_lights	*tmp;
	double		n_dot_l;

	n_dot_l = 0;
	tmp = scene->lights;
	while(tmp)
	{
		printf("hey\n");
		light_vec = sub_vec(tmp->point_light->pos, point);
		n_dot_l = prod_scal(normal, light_vec);
		// add  color of the lamp
		if(n_dot_l > 0)
			light_calc(color, tmp->point_light->lum, tmp->point_light->color);
		tmp = tmp->next;
	}
}

t_vec	normal_calc(t_vec point, t_objects	*closest_object)
{
	t_vec		normal;
	t_sphere	*tmp_s;

	init_vec(&normal);
	if(closest_object->id == (int)'s')
	{
		tmp_s = (t_sphere *)closest_object->obj;
		normal = sub_vec(point, tmp_s->pos);
	}
	normal = normalized(normal);
	return(normal);
}

void	process_light(t_color *color, t_scene *scene, t_objects	*closest_object, double	closest_t, t_ray *ray)
{	
	t_vec 	point;
	t_vec	normal;

	point = add_vec(scene->active_camera->pos, mult_point_d(ray->dir, closest_t));
	normal = normal_calc(point, closest_object);
	// point light process
	point_light(scene, point, normal, color);
	// whole light process
	light_calc(color, scene->ambient_light.lum, scene->ambient_light.color);
}

int		trace_ray(t_ray *ray, t_scene *scene){
	t_color		color;
	double		closest_t;
	t_objects	*tmp;
	t_objects	*closest_object;

	tmp = scene->objects;

	//int count = 1;
	closest_object = NULL;
	closest_t = __DBL_MAX__;
	while(tmp)
	{
		intersect_object(scene, ray, tmp);
		if(ray->inter.t1 > 0 && ray->inter.t1 < __DBL_MAX__ && ray->inter.t1 < closest_t)
		{
			closest_t = ray->inter.t1;
			closest_object = tmp;
		}
		if(ray->inter.t2 > 0 && ray->inter.t2 < __DBL_MAX__ && ray->inter.t2 < closest_t)
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
	process_light(&color, scene, closest_object, closest_t, ray);
	return(get_color_integer(color.r, color.g, color.b));
}

void	ft_init_mlx(t_mlx *mlx, t_scene *scene)
{
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, scene->window_width, scene->window_height, "MiniRT");
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, scene->window_width, scene->window_height);
	mlx->img_data = (int*)mlx_get_data_addr(mlx->img_ptr, &mlx->bpp, &mlx->size_line, &mlx->endian);
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
