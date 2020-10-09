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

int     ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

void     ft_putstr(char *str)
{
    write(0, str, ft_strlen(str));
}


float		distance(float Xa, float Ya, float Xb, float Yb)
{
	float result;

	result = sqrt(((Xa - Xb) * (Xa - Xb)) + ((Ya - Yb) * (Ya - Yb)));
	return(result);
}

void		get_coordinates(int *x_point, int *y_point, t_zone *zone, int i)
{
	*y_point = i / zone->width;
	*x_point = i % zone->width;
}

int		is_inside(float x_point, float y_point, t_shape *shape)
{
	if (distance(x_point, y_point, (float)shape->x, (float)shape->y) <= shape->radius)
		return (1);
	return (0);
}

int		is_border(float x_point, float y_point, t_shape *shape)
{
	float dist = distance(x_point, y_point, (float)shape->x, (float)shape->y);

	if (dist <= shape-> radius && shape->radius - dist < 1)
		return (1);
	return (0);
}

void		draw_shape(char *drawing, t_shape *shape, t_zone *zone)
{
	int i;
	int x_point;
	int y_point;

	i = 0;
	while (drawing[i])
	{
		get_coordinates(&x_point, &y_point, zone, i);
		if (is_border(x_point, y_point, shape))
			drawing[i] = shape->c;
		if (shape->type == 'C')
		{
			if (is_inside((float)x_point, (float)y_point, shape))
				drawing[i] = shape->c;
		}
		i++;
	}
}

int		check_zone(t_zone	*zone)
{
	if (zone->width > MAX_SIZE || zone->height > MAX_SIZE ||
		zone->width <= 0 || zone->height <= 0 ||
		!(zone->bg_char >= 32 && zone->bg_char <= 126))
		return (0);
	return (1);
}

int     check_background(FILE *file, t_zone *zone)
{
	if ((fscanf(file, "%d %d %c\n", &zone->width, &zone->height, &zone->bg_char)) != 3)
		return (0);
	if (!check_zone(zone))
		return (0);
	return (1);
}

char	*fill_bg(t_zone *zone)
{
	int		zone_len;
	int		width;
	int		height;
	int		i;
	char	*str;

	width = 0;
	height = 0;
	i = 0;
	zone_len = zone->width * zone->height;
	if (!(str = malloc(sizeof(char) * zone_len + 1)))
		return (NULL);
	while (height < zone->height)
	{
		while (width < zone->width)
		{
			str[i] = zone->bg_char;
			i++;
			width++;
		}
		width = 0;
		height++;
	}
	str[zone_len] = '\0';
	return (str);
}

void	print_drawing(char *drawing, t_zone *zone)
{
	int	i;

	i = 0;
	while (i < zone->height)
	{
		write(1, drawing + (i * zone->width), zone->width);
		write(1, "\n", 1);
		i++;
	}
}

int		test_shape(t_shape *shape)
{
	if (shape->radius <= 0 ||
		shape->c == '\0' ||
		(shape->type != 'c' && shape->type != 'C'))
		return (0);
	return (1);
}

int		get_shapes(FILE *file, char *drawing, t_zone *zone)
{
	t_shape	shape;
	int		ret;
	while ((ret = fscanf(file, "%c %f %f %f %c\n", &shape.type, &shape.x, &shape.y, &shape.radius, &shape.c)) == 5)
	{
		if (!test_shape(&shape))
			return (0);
		draw_shape(drawing, &shape, zone);
	}
	if (ret == -1)
		return (1);
	return (0);
}

int     main(int argc, char **argv)
{
	FILE	*file;
	t_zone	zone;
	char	*drawing;

	if (argc != 2)
	{
		ft_putstr("Error: argument\n");
		return (MAIN_ERROR);
	}
    else
	{
		if ((file = fopen(argv[1], "r")) == NULL)
		{
			ft_putstr("Error: Operation file corrupted\n");
			return (MAIN_ERROR);
		}
		if (!check_background(file, &zone))
		{
			fclose(file);
			ft_putstr("Error: Operation file corrupted\n");
			return (MAIN_ERROR);
		}
		if (!(drawing = fill_bg(&zone)))
		{
			fclose(file);
			return (MAIN_ERROR);
		}
		if (!(get_shapes(file, drawing, &zone)))
		{
			fclose(file);
			ft_putstr("Error: Operation file corrupted\n");
			return (MAIN_ERROR);
		}
		print_drawing(drawing, &zone);
		fclose(file);
		free(drawing);
		return (MAIN_ALLGOOD);
	}
}