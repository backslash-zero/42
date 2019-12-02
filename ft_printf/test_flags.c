/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 16:50:40 by cmeunier          #+#    #+#             */
/*   Updated: 2019/12/02 18:39:24 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_test_flags(t_ftprint *p)
{
	ft_test_zero(p);
	ft_test_minus(p);
	ft_test_plus(p);
}

void	ft_test_minus(t_ftprint *p)
{
	if (p->str[p->i] == '-')
	{
		p->flag_minus = 1;
	}
}

void	ft_test_plus(t_ftprint *p)
{
	if (p->str[p->i] == '+')
	{
		p->flag_plus = 1;
	}
}

void	ft_test_zero(t_ftprint *p)
{
	if (p->str[p->i] == '0')
	{
		p->flag_zero = 1;
		while (p->str[p->i] == '0')
			p->i++;
	}
}
