/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 13:44:50 by cmeunier          #+#    #+#             */
/*   Updated: 2020/04/28 15:05:40 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_MLX_H
# define RT_MLX_H

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
	int		fd;
}				t_rt;

void			ft_init_mlx(t_mlx *mlx, t_scene *scene);
void			put_image(t_rt *rt);
void			put_image_and_start(t_rt *rt);
void			start_window(t_rt *rt);
void			display_image(t_rt *rt);
int				ft_key_ambient_light(int key, t_rt *rt);
int				ft_key_pos(int key, t_rt *rt);
int				ft_key_rot(int key, t_rt *rt);
int				ft_key_switch(int key, t_rt *rt);
int				ft_key_fov(int key, t_rt *rt);
int				ft_key_invert_colors(int key, t_rt *rt);
int				ft_key(int key, t_rt *rt);

#endif
