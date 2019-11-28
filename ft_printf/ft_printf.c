/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 11:37:30 by cmeunier          #+#    #+#             */
/*   Updated: 2019/11/28 17:53:51 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

void	ft_key(t_ftprint *p)
{
	if (p->str[p->i] == 's')
		print_s(p);
	if (p->str[p->i] == 'c' || p->str[p->i] == '%')
		print_c(p);
	if (p->str[p->i] == 'p')
		print_p(p);
	if (p->str[p->i] == 'd' || p->str[p->i] == 'i')
		print_d(p);
	if (p->str[p->i] == 'u')
		print_u(p);
}

int		ft_printf(const char *format, ...)
{
	t_ftprint pf;

	pf = (t_ftprint) { .str = (char *)format };
	va_start(pf.list, format);
	while (pf.i < (int)ft_strlen(format))
	{
		if (pf.str[pf.i] == '%')
		{
			pf.i++;
			ft_key(&pf);
		}
		else
		{
			ft_putchar(pf.str[pf.i]);
			pf.count++;
		}
		if (pf.str[pf.i] != '\0')
			pf.i++;
	}
	va_end(pf.list);
	return (pf.count);
}
