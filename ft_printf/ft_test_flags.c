/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 16:50:40 by cmeunier          #+#    #+#             */
/*   Updated: 2019/12/07 00:53:11 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

void	ft_test_flags(t_ftprint *p)
{
	while (ft_is_special(p))
	{
		ft_test_zero(p);
		ft_test_minus(p);
		ft_test_plus(p);
		ft_test_star(p);
		ft_test_size(p);
		ft_test_precision(p);
	}
}

void	ft_test_minus(t_ftprint *p)
{
	while (p->str[p->i] == '-')
	{
		p->flag_minus = 1;
		p->i++;
	}
}

void	ft_test_plus(t_ftprint *p)
{
	if (p->str[p->i] == '+')
	{
		p->flag_plus = 1;
		p->i++;
	}
}

void	ft_test_zero(t_ftprint *p)
{
	while (p->str[p->i] == '0')
	{
		p->flag_zero = 1;
		while (p->str[p->i] == '0')
			p->i++;
	}
}

void	ft_test_star(t_ftprint *p)
{
	if (p->str[p->i] == '*')
	{
		p->flag_star = 1;
		p->i++;
		ft_size_flagstar(p);
	}
}

void	ft_test_precision(t_ftprint *p)
{
	if (p->str[p->i] == '.')
	{
		p->flag_precision = 1;
		p->i++;
		ft_getprecision(p);
	}
}

void	ft_test_size(t_ftprint *p)
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
