#ifndef RT_MLX_H
# define RT_MLX_H


typedef	struct	s_mlx
{
	void	*win_ptr;
	void	*mlx_ptr;
	void	*img_ptr;
}				t_mlx;

void	ft_init_mlx(t_mlx *mlx, t_scene *scene);

#endif