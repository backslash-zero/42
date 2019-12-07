/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_field_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 18:15:16 by cmeunier          #+#    #+#             */
/*   Updated: 2019/12/07 00:51:59 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

void	ft_size_flagstar(t_ftprint *p)
{
	int value;

	value = 0;
	value = va_arg(p->list, int);
	if (value < 0)
	{
		if (p->flag_precision)
			p->field_precision = -value;
		else
			p->field_width = -value;
		p->flag_minus = 1;
	}
	else
	{
		if (p->flag_precision)
			p->field_precision = value;
		else
			p->field_width = value;
	}
	p->i++;
	p->flag_star = 0;
}

void	ft_size_default(t_ftprint *p)
{
	int value;

	value = 0;
	while (p->str[p->i] >= '0' && p->str[p->i] <= '9')
	{
		value *= 10;
		value += p->str[p->i] - 48;
		p->i++;
	}
	p->field_width = value;
}

void	ft_tests_checks(t_ftprint *p)
{
	if (p->flag_precision)
		ft_print_precision(p);
	else
		ft_print_field_width(p);
}

void	ft_print_field_width(t_ftprint *p)
{
	char padding_char;

	padding_char = ' ';
	if (p->str[p->i] != 'd' ||
			p->str[p->i] != 'i' ||
			p->str[p->i] != 'u' ||
			p->str[p->i] != 'x' ||
			p->str[p->i] != 'X')
	{
		if (p->flag_zero == 1)
			padding_char = '0';
	}
	while (p->field_width - p->arg_len > 0)
	{
		ft_putchar(padding_char);
		p->count++;
		p->field_width--;
	}
}

