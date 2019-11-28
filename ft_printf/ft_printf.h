#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_ftprint
{
	va_list		list;
	int			i;
	int			count;
	char		*str;
}				t_ftprint;

//void			ft_printf(const char *format, ...);
int			ft_printf(const char *format, ...);
size_t		ft_strlen(const char *s);
void		ft_putchar(char c);
void		ft_putstr(char *s);
void		print_s(t_ftprint *p);
void		print_c(t_ftprint *p);
void		print_p(t_ftprint *p);
void		print_d(t_ftprint *p);
void		ft_putnbr_hex(size_t nb);
int			ft_putnbr_len(int nb);
void		print_u(t_ftprint *p);

#endif