#include "./micro_paint.h"

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
