/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_print_other.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 12:57:32 by cmeunier          #+#    #+#             */
/*   Updated: 2019/12/06 14:37:20 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

void	print_d_intmin(t_ftprint *p)
{
	if (p->flag_precision || p->flag_zero)
	{
		ft_putchar('-');
		if (p->flag_precision)
			p->arg_len = 10;
		else
			p->arg_len = 11;

		ft_tests_checks(p);
		ft_putstr("2147483648");
		p->count += 11;
	}
	else
	{
		p->arg_len = 11;
		ft_tests_checks(p);
		ft_putstr("-2147483648");
		p->count += 11;
	}
}

void	print_d_negative(t_ftprint *p, int *nb)
{
	if (p->flag_precision)
	{
		ft_putchar('-');
		p->count += 1;
		p->nb_neg = 1;
		*nb = -*nb;
	}
	else
		p->nb_len += 1;
}

void	print_d(t_ftprint *p)
{
	int		nb;
	char	*str;

	nb = va_arg(p->list, int);
	ft_get_number_len(p, nb, 10);
	if (nb < 0 && nb != -2147483648)
		print_d_negative(p, &nb);
	if (nb != -2147483648)
	{
		str = ft_number_str(nb, p);
		p->arg_len = p->nb_len;
		ft_tests_checks(p);
		ft_putstr(str);
		p->count += p->arg_len;
		free(str);
	}
	else
		print_d_intmin(p);
}

void	print_p(t_ftprint *p)
{
	void	*str;
	size_t	address;

	str = va_arg(p->list, void *);
	address = (size_t)str;
	p->arg_len = 14;
	ft_tests_checks(p);
	ft_putstr("0x");
	ft_putnbr_hex_len(address, "0123456789abcdef");
	p->count += 14;
}

void	print_u(t_ftprint *p)
{
	unsigned int	nb;
	char			*str;

	nb = va_arg(p->list, unsigned int);
	ft_get_number_len_u(p, nb, 10);
	str = ft_number_str_u(nb, p, 10, "0123456789");
	p->arg_len = p->nb_len;
	ft_tests_checks(p);
	ft_putstr(str);
	p->count += p->arg_len;
	free(str);
}

void	print_x_low(t_ftprint *p)
{
	unsigned int	nb;
	char			*str;

	nb = va_arg(p->list, unsigned int);
	ft_get_number_len_u(p, nb, 16);
	str = ft_number_str_u(nb, p, 16, "0123456789abcdef");
	p->arg_len = p->nb_len;
	ft_tests_checks(p);
	ft_putstr(str);
	p->count += p->arg_len;
	free(str);
}

void	print_x_up(t_ftprint *p)
{
	unsigned int	nb;
	char			*str;

	nb = va_arg(p->list, unsigned int);
	ft_get_number_len_u(p, nb, 16);
	str = ft_number_str_u(nb, p, 16, "0123456789ABCDEF");
	p->arg_len = p->nb_len;
	ft_tests_checks(p);
	ft_putstr(str);
	p->count += p->arg_len;
	free(str);
}
