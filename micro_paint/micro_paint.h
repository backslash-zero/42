#ifndef MICRO_PAINT_H
# define MICRO_PAINT_H

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <math.h>

# define MAIN_ERROR		1
# define MAIN_ALLGOOD	0
# define MAX_SIZE		300


typedef struct		s_zone
{
	int				width;
	int				height;
	char			bg_char;
}					t_zone;

typedef struct		s_shape
{
	char			type;
	float			x;
	float			y;
	float			radius;
	char			c;
}					t_shape;

int		ft_strlen(char *str);
void	ft_putstr(char *str);
void	draw_shape(char *drawing, t_shape *shape, t_zone *zone);

#endif