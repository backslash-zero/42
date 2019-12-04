/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_print_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 12:57:32 by cmeunier          #+#    #+#             */
/*   Updated: 2019/12/04 16:27:35 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

void	print_s(t_ftprint *p)
{
	char *s;

	s = va_arg(p->list, char *);
	p->arg_len = ft_strlen(s);
	ft_tests_checks(p);
	if (p->flag_precision && (p->field_width < (int)ft_strlen(s)))
	{
		s = ft_substr(s, 0, p->field_width);
		p->arg_len = p->field_width;
		ft_putstr(s);
		free(s);
	}
	else
		ft_putstr(s);
	p->count += p->arg_len;
}

void	print_c(t_ftprint *p)
{
	char c;

	p->arg_len = 1;
	ft_tests_checks(p);
	if (p->str[p->i] == '%')
		ft_putchar('%');
	else
	{
		c = (char)va_arg(p->list, int);
		ft_putchar(c);
	}
	p->count += 1;
}
