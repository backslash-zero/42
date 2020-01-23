/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:25:41 by cmeunier          #+#    #+#             */
/*   Updated: 2020/01/23 16:05:57 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int		main(int ac, char **av)
{
	(void)av;
	if(ac == 2)
	{
		parsing_scene(av[1]);
		int size = 800;
		int color = 0xffffff;
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
				mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
				y++;
			}
			y = 0;
			x++;
		}
		mlx_loop(mlx_ptr);
	}
	else
	{
		// error number of arguments
	}
	return(0);
}