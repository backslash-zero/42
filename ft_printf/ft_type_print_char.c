/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_print_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 12:57:32 by cmeunier          #+#    #+#             */
/*   Updated: 2019/12/09 23:12:42 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

void	print_s(t_ftprint *p)
{
	char *s;

	//protect for NULL string;
	s = va_arg(p->list, char *);
	p->arg_len = ft_strlen(s);
	if (p->field_precision < (int)ft_strlen(s) && p->flag_precision)
		p->arg_len = p->field_precision;
	if (!p->flag_minus)
		ft_print_field_width(p);
	if (p->field_precision < (int)ft_strlen(s) && p->flag_precision)
	{
		s = ft_substr(s, 0, p->field_precision);
		ft_putstr(s);
		free(s);
	}
	else
		ft_putstr(s);
	if (p->flag_minus)
		ft_print_field_width(p);
	p->count += p->arg_len;
}

void	print_c(t_ftprint *p)
{
	char c;

	p->arg_len = 1;
	if (!p->flag_minus)
		ft_print_field_width(p);
	if (p->str[p->i] == '%')
		ft_putchar('%');
	else
	{
		c = (char)va_arg(p->list, int);
		ft_putchar(c);
	}
	if (p->flag_minus)
		ft_print_field_width(p);
	p->count += 1;
}

void	print_p(t_ftprint *p)
{
	void	*str;
	size_t	address;

	str = va_arg(p->list, void *);
	address = (size_t)str;
	p->arg_len = 14;
	if (!p->flag_minus)
		ft_print_field_width(p);
	ft_putstr("0x");
	ft_putnbr_hex_len(address, "0123456789abcdef");
	if (p->flag_minus)
		ft_print_field_width(p);
	p->count += 14;
}
