/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_zero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 16:50:40 by cmeunier          #+#    #+#             */
/*   Updated: 2019/11/29 18:25:29 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_test_zero(t_ftprint *p)
{
	if (p->str[p->i] == '0')
	{
		p->str[p->flag_zero] = 1;
		while (p->str[p->i] == '0')
			p->i++;
	}
	/* if (p->str[p->i] == '0')
	{
		p->i++;
		if (p->str[p->i] == 'd' ||
			p->str[p->i] == 'i' ||
			p->str[p->i] == 'u' ||
			p->str[p->i] == 'x' ||
			p->str[p->i] == 'X')
			return (0);
		else
			return (1);
	}
	return (0); */
}
