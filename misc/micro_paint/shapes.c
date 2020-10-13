#include "./micro_paint.h"

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
