/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_print_other.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 12:57:32 by cmeunier          #+#    #+#             */
/*   Updated: 2019/12/01 19:12:21 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

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

void	print_d(t_ftprint *p)
{
	int d;

	d = va_arg(p->list, int);
	if (d != -2147483648)
		p->count += ft_putnbr_len(d);
	else
	{
		ft_putstr("-2147483648");
		p->count += 11;
	}
}

void	print_u(t_ftprint *p)
{
	unsigned int u;

	u = va_arg(p->list, unsigned int);
	p->count += ft_u_putnbr_len(u);
}

void	print_x_low(t_ftprint *p)
{
	void	*str;
	size_t	address;

	str = va_arg(p->list, void *);
	address = (size_t)str;
	p->count += ft_putnbr_hex_len(address, "0123456789abcdef");
}

void	print_x_up(t_ftprint *p)
{
	void	*str;
	size_t	address;

	str = va_arg(p->list, void *);
	address = (size_t)str;
	p->count += ft_putnbr_hex_len(address, "0123456789ABCDEF");
}
