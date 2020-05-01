/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:25:41 by cmeunier          #+#    #+#             */
/*   Updated: 2020/05/01 16:23:50 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minirt.h"

int		trace_ray(t_ray *ray, t_scene *scene)
{
	intersection(ray, scene);
	if (ray->closest_object == NULL)
		return (get_color_integer(255, 255, 255));
	process_light(scene, ray);
	if (scene->invert)
		invert_color(&ray->color);
	return (get_color_integer(ray->color.r, ray->color.g, ray->color.b));
}

void	fill_img(t_scene *scene, t_mlx *mlx)
{
	int		x;
	int		y;
	int		len;
	t_ray	ray;

	viewport_parsing(scene);
	len = mlx->size_line / 4;
	y = -1;
	while (++y < scene->window_height)
	{
		x = -1;
		while (++x < scene->window_width)
		{
			init_vec(&ray.dir, 0, 0, 0);
			ray.origin = scene->active_camera->pos;
			ray.dir = add_vec(ray.dir, scene->active_camera->dir_z);
			ray.dir = add_vec(ray.dir, mult_point_d(scene->active_camera->dir_x,
								get_vp_x(center_x(x, scene), scene)));
			ray.dir = add_vec(ray.dir, mult_point_d(scene->active_camera->dir_y,
								get_vp_y(center_y(y, scene), scene)));
			mlx->img_data[y * len + x] = trace_ray(&ray, scene);
		}
	}
}

int		main(int ac, char **av)
{
	t_rt				rt;
	t_scene				scene;
	t_mlx				mlx;

	rt.mlx = &mlx;
	rt.scene = &scene;
	if (ac == 2 || ac == 3)
	{
		if (!check_extension(av[1]))
			exit_formatfail();
		if ((scene.fd = open(av[1], O_RDONLY)) == -1)
			exit_openfail();
		scene_parsing(&rt);
		ft_init_mlx(&mlx, &scene);
		fill_img(&scene, &mlx);
		if (ac == 3 && !ft_strncmp(av[2], "-save", 5))
			save_image(&rt, "save.bmp");
		if (ac == 2)
			put_image_and_start(&rt);
		else
			parsing_err(&rt, "Third argument is not valid.", -1);
	}
	else
		parsing_err(&rt, "Incorrect ammout of arguments.", -1);
	return (0);
}
