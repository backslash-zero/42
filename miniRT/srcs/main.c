/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:25:41 by cmeunier          #+#    #+#             */
/*   Updated: 2020/01/24 21:57:13 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int		center_x(int x)
{
	x = x + (VIEWPORT_SIZE_X / 2);
	return(x);
}

int		center_y(int y)
{
	y = y + (VIEWPORT_SIZE_Y / 2);
	return(y);
}

int		min_max_color(int value)
{
	if(value < 0)
		return(0);
	if(value > 255)
		return(255);
	return(value);
}

int get_color_integer(int r, int g, int b)
{
	int rt;

	rt = 0;
	rt |= min_max_color(r) << 16;
	rt |= min_max_color(g) << 8;
	rt |= min_max_color(b);
	return (rt);
}

int		main(int ac, char **av)
{
	(void)av;
	if(ac == 2)
	{
		//parsing_scene(av[1]);
		int color = get_color_integer(217, 3, 104);
		void *win_ptr;
		void *mlx_ptr;

		mlx_ptr = mlx_init();
		win_ptr = mlx_new_window(mlx_ptr, VIEWPORT_SIZE_X, VIEWPORT_SIZE_Y, "MiniRT");

		int x = 0;
		int y = 0;
		while(x < VIEWPORT_SIZE_X)
		{
			while(y < VIEWPORT_SIZE_Y)
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