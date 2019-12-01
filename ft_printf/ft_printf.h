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
	int			flag_zero;
	int			field_width;
	int			arg_len;
	int			nb_len;
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
void		print_u(t_ftprint *p);
void		print_x_low(t_ftprint *p);
void		print_x_up(t_ftprint *p);
int			ft_putnbr_hex_len(size_t nb, char *base);
int			ft_putnbr_len(int nb);
int			ft_u_putnbr_len(unsigned int nb);
void		ft_test_zero(t_ftprint *p);
void		ft_test_field_width(t_ftprint *p);
void		ft_tests_checks(t_ftprint *p);
void		ft_reset_struct(t_ftprint *p);

#endif