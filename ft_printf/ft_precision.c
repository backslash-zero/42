/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 23:54:49 by cmeunier          #+#    #+#             */
/*   Updated: 2019/12/07 00:25:14 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

void	ft_getprecision(t_ftprint *p)
{
	if (p->str[p->i] == '*')
	{
		p->field_precision = va_arg(p->list, int);
		p->i++;
	}
	else
		ft_precision_default(p);
}

void	ft_precision_default(t_ftprint *p)
{
	int value;

	value = 0;
	while (p->str[p->i] >= '0' && p->str[p->i] <= '9')
	{
		value *= 10;
		value += p->str[p->i] - 48;
		p->i++;
	}
	p->field_precision = value;
}

void	ft_print_precision(t_ftprint *p)
{
	if (p->str[p->i] == 'd' ||
			p->str[p->i] == 'i' ||
			p->str[p->i] == 'u' ||
			p->str[p->i] == 'x' ||
			p->str[p->i] == 'X')
	{
		while (p->field_precision - p->arg_len > 0)
		{
			ft_putchar('0');
			p->count++;
			p->field_precision--;
		}
	}
}
