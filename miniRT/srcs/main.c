/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:25:41 by cmeunier          #+#    #+#             */
/*   Updated: 2020/01/25 18:37:20 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int		center_x(int x)
{
	x = (WINDOW_WIDTH / 2) + x;
	return(x);
}

int		center_y(int y)
{
	y = (WINDOW_HEIGHT / 2) - y;
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

double get_vp_x(int x)
{
	double vp_x;

	vp_x = x * VIEWPORT_WIDTH / WINDOW_WIDTH;
	return(vp_x);
}

double get_vp_y(int y)
{
	double vp_y;

	vp_y = y * VIEWPORT_HEIGHT / WINDOW_HEIGHT;
	return(vp_y);
}

double get_vp_z(int z)
{
	double vp_z;

	vp_z = VIEWPORT_HEIGHT;
	return(vp_z);
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
		win_ptr = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "MiniRT");

		int x = 0;
		int y = 0;
		while(x < VIEWPORT_WIDTH)
		{
			while(y < VIEWPORT_HEIGHT)
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