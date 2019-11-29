/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tests_checks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 18:29:51 by cmeunier          #+#    #+#             */
/*   Updated: 2019/11/29 18:47:08 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_tests_checks(t_ftprint *p)
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
	p->flag_zero = 0;
	while (p->field_width > 0)
	{
		ft_putchar(padding_char);
		p->count++;
		p->field_width--;
	}
}
