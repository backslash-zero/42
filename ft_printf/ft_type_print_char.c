/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_print_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 12:57:32 by cmeunier          #+#    #+#             */
/*   Updated: 2019/12/07 00:55:56 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

void	print_s(t_ftprint *p)
{
	char *s;

	s = va_arg(p->list, char *);
	p->arg_len = ft_strlen(s);
	if (!p->flag_minus)
		ft_print_field_width(p);
	if (p->flag_precision && (p->field_precision < (int)ft_strlen(s)))
	{
		s = ft_substr(s, 0, p->field_precision);
		p->arg_len = p->field_precision;
		ft_putstr(s);
		free(s);
	}
	else
		ft_putstr(s);
	if (p->flag_minus)
	{
		ft_print_field_width(p);
		p->arg_len += p->field_width;
	}
	p->count += p->arg_len;
}

void	print_c(t_ftprint *p)
{
	char c;

	p->arg_len = 1;
	if (!p->flag_minus)
		ft_tests_checks(p);
	if (p->str[p->i] == '%')
		ft_putchar('%');
	else
	{
		c = (char)va_arg(p->list, int);
		ft_putchar(c);
	}
	if (p->flag_minus)
		ft_tests_checks(p);
	p->count += 1;
}
