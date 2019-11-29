/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_print_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 12:57:32 by cmeunier          #+#    #+#             */
/*   Updated: 2019/11/29 15:31:06 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

void	print_s(t_ftprint *p)
{
	char *s;

	s = va_arg(p->list, char *);
	ft_putstr(s);
	p->count += ft_strlen(s);
}

void	print_c(t_ftprint *p)
{
	char c;

	if (p->str[p->i] == '%')
		ft_putchar('%');
	else
	{
		c = (char)va_arg(p->list, int);
		ft_putchar(c);
	}
	p->count++;
}
