/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:38:57 by cmeunier          #+#    #+#             */
/*   Updated: 2020/03/09 15:25:26 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

void	write_bmp_file_header(t_rt *rt, int fd)
{
	t_fileheader fileheader;

	ft_bzero(&fileheader, sizeof(t_fileheader));
	fileheader.id = 19778;
	fileheader.size = 54 + (rt->scene->window_height * rt->scene->window_width * 3);
	fileheader.reserved = 0;
	fileheader.offset = 54;
	write(fd, &fileheader.id, 2);
	write(fd, &fileheader.size, 4);
	write(fd, &fileheader.reserved, 4);
	write(fd, &fileheader.offset, 4);
}

void	write_bmp_dib_header(t_rt *rt, int fd)
{
	t_dibheader dibheader;

	ft_bzero(&dibheader, sizeof(t_dibheader));
	dibheader.headersize = sizeof(t_dibheader);
	dibheader.width = rt->scene->window_width;
	dibheader.height = rt->scene->window_height;
	dibheader.pane = 1;
	dibheader.bitcount = 24;
	write(fd, &dibheader.headersize, 4);
	write(fd, &dibheader.width, 4);
	write(fd, &dibheader.height, 4);
	write(fd, &dibheader.pane, 2);
	write(fd, &dibheader.bitcount, 2);
	write(fd, &dibheader.offset, 24);
}

void	write_bmp_pixeldata(t_rt *rt, int fd)
{
	unsigned char	*tab;
	int				i;
	int 			x;
	int 			y;
	
	tab = malloc(rt->scene->window_height * rt->scene->window_width * 3);
	i = 0;
	y = rt->scene->window_height;
	while(--y > 0)
	{
		x = -1;
		while(++x < rt->scene->window_width)
		{	
			tab[i * 3] = rt->mlx->img_data[x + y * (int)rt->scene->window_width] >> 0;
			tab[(i * 3) + 1] = rt->mlx->img_data[x + y * (int)rt->scene->window_width] >> 8;
			tab[(i * 3) + 2] = rt->mlx->img_data[x + y * (int)rt->scene->window_width] >> 16;
			i++;
		}
	}
	write(fd, tab, rt->scene->window_width * rt->scene->window_height *3);
	free(tab);
}

void	save_image(t_rt *rt, char *filename)
{
	int fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	write_bmp_file_header(rt, fd);
	write_bmp_dib_header(rt, fd);
	write_bmp_pixeldata(rt, fd);
	exit_free_all(rt->scene);
}
