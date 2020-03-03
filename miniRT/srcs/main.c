/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:25:41 by cmeunier          #+#    #+#             */
/*   Updated: 2020/03/03 15:20:58 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int		trace_ray(t_ray *ray, t_scene *scene)
{
	intersection(ray, scene);
	if(ray->closest_object == NULL)
		return(get_color_integer(255, 255, 255));
	process_light(scene, ray);
	return(get_color_integer(ray->color.r, ray->color.g, ray->color.b));
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
			init_vec(&ray.dir, 0, 0, 0);
			ray.origin = scene->active_camera->pos;
			ray.dir = add_vec(ray.dir, scene->active_camera->dir_z);
			ray.dir = add_vec(ray.dir, mult_point_d(scene->active_camera->dir_x, get_vp_x(center_x(x, scene), scene)));
			ray.dir = add_vec(ray.dir, mult_point_d(scene->active_camera->dir_y, get_vp_y(center_y(y, scene), scene)));
			mlx->img_data[y * len + x] = trace_ray(&ray, scene);
		}
	}
}

int		main(int ac, char **av)
{
	(void)av;
	t_rt				rt;
	t_scene				scene;
	t_mlx				mlx;

	rt.mlx = &mlx;
	rt.scene = &scene;

	if(ac == 2 || ac == 3)
	{
		rt.fd = open(av[1], O_RDONLY);
		scene_parsing(&scene);
		ft_init_mlx(&mlx, &scene);
/* 		printf("\n** INFO:\n");
		printf("**\n** scene.window_width: 				%f\n", scene.window_width);
		printf("**\n** scene.window_height: 			%f\n", scene.window_height);
		printf("**\n** scene.viewport_d: 				%f\n", scene.viewport_d);
		printf("**\n** scene.viewport_height: 			%f\n", scene.viewport_height);
		printf("**\n** scene.viewport_width: 			%f\n", scene.viewport_width);
		printf("**\n** camera.fov: 					%f\n", scene.active_camera->fov);
		printf("**\n** camera.pos.x: 				%f\n", scene.active_camera->pos.x);
		printf("**\n** camera.pos.y: 				%f\n", scene.active_camera->pos.y);
		printf("**\n** camera.pos.z: 				%f\n", scene.active_camera->pos.z); */
		fill_img(&scene, &mlx);
		if (ac == 2)
		{
			mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img_ptr, 0, 0);
			start_window(&rt);
		}
		else if(ac == 3 && !ft_strncmp(av[2], "-save", 5))
			save_image(&rt, "save.bmp");
		/* else
			error(); */
		// we need to FREE objects when exiting program
	}
	else
	{
		//else
			// error number of arguments parsed
	}
	return(0);
}
