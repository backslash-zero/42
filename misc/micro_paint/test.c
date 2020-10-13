#include "./micro_paint.h"

void		get_coordinates(int *x_point, int *y_point, t_zone *zone, int i)
{
	*y_point = i / zone->width;
	*x_point = i % zone->width;
}

int     main(void)
{
    t_zone zone;
    int x_point;
    int y_point;
    zone.width = 3;
    zone.height = 3;
    get_coordinates(&x_point, &y_point, &zone, 5);
    printf("x_point: %d\ny_point: %d\n", x_point, y_point);
}