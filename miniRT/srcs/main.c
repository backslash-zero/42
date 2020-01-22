/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:25:41 by cmeunier          #+#    #+#             */
/*   Updated: 2020/01/22 21:14:52 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../incs/miniRT.h"
#include <mlx.h>
#include <unistd.h>

int		main()
{
	// Initialize mlx
	int size = 800;
	int color = 0xff5d6c;
	void *win_ptr;
	void *mlx_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, size, size, "MiniRT");

	int x = 0;
	int y = 0;
	while(x < size)
	{
		while(y < size)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, color * 4);
			y++;
		}
		y = 0;
		x++;
	}
	mlx_loop(mlx_ptr);


	return(0);
}