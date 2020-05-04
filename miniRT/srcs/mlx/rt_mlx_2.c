/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_mlx_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 16:47:57 by cmeunier          #+#    #+#             */
/*   Updated: 2020/04/30 11:01:25 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minirt.h"

void	ft_mlx_max_size(t_scene *scene)
{
	void	*screen;
	int		max_w;
	int		max_h;

	screen = mlx_init();
	mlx_get_screen_size(screen, &max_w, &max_h);
	if (scene->window_width >= max_w)
		scene->window_width = max_w;
	if (scene->window_height >= max_h)
		scene->window_height = max_h;
	free(screen);
}

void	ft_init_mlx(t_mlx *mlx, t_scene *scene)
{
	mlx->mlx_ptr = mlx_init();
	ft_mlx_max_size(scene);
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr,
					scene->window_width, scene->window_height);
	mlx->img_data = (int*)mlx_get_data_addr(mlx->img_ptr,
					&mlx->bpp, &mlx->size_line, &mlx->endian);
}

int		rt_loop(t_mlx mlx)
{
	(void)mlx;
	return (0);
}
