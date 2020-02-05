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

void	ft_init_mlx(t_mlx *mlx, t_scene *scene);
void	start_window(t_mlx *mlx);
int		ft_quit(t_mlx *mlx);

#endif