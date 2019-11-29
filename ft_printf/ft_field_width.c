/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_field_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 18:15:16 by cmeunier          #+#    #+#             */
/*   Updated: 2019/11/29 18:45:21 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_test_field_width(t_ftprint *p)
{
	int value;

	value = 0;
	while (p->str[p->i] >= '0' && p->str[p->i] <= '9')
	{
		value *= 10;
		value += 48 - p->str[p->i];
		p->i++;
	}
	p->field_width = value;
}
