/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_bmp.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 18:04:14 by cmeunier          #+#    #+#             */
/*   Updated: 2020/03/12 14:23:42 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_BMP_H
# define RT_BMP_H

typedef	struct	s_fileheader
{
	unsigned short int	id;
	unsigned int		size;
	unsigned int		reserved;
	unsigned int		offset;
}				t_fileheader;

typedef	struct	s_dibheader
{
	unsigned int		headersize;
	unsigned int		width;
	unsigned int		height;
	unsigned short int	pane;
	unsigned short int	bitcount;
	unsigned char		offset[24];
}				t_dibheader;

void			write_bmp_file_header(t_rt *rt, int fd);
void			write_bmp_dib_header(t_rt *rt, int fd);
void			write_bmp_pixeldata(t_rt *rt, int fd);
void			save_image(t_rt *rt, char *filename);

#endif
