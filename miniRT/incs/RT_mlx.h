/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RT_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 13:44:50 by cmeunier          #+#    #+#             */
/*   Updated: 2020/02/29 19:43:23 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_MLX_H
# define RT_MLX_H

# include "miniRT.h"

typedef	struct	s_mlx
{
	void	*win_ptr;
	void	*mlx_ptr;
	void	*img_ptr;
	int		*img_data;
	int		bpp;
	int		size_line;
	int		endian;
}				t_mlx;

typedef	struct	s_rt
{
	t_mlx	*mlx;
	t_scene	*scene;
}				t_rt;

void	ft_init_mlx(t_mlx *mlx, t_scene *scene);
void	start_window(t_rt *rt);
int		ft_key(int key, t_rt *rt);

#endif