/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RT_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 13:42:28 by cmeunier          #+#    #+#             */
/*   Updated: 2020/02/28 13:44:25 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

void	ft_init_mlx(t_mlx *mlx, t_scene *scene)
{
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, scene->window_width, scene->window_height, "MiniRT");
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, scene->window_width, scene->window_height);
	mlx->img_data = (int*)mlx_get_data_addr(mlx->img_ptr, &mlx->bpp, &mlx->size_line, &mlx->endian);
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
