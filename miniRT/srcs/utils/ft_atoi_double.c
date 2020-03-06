/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 18:22:18 by cmeunier          #+#    #+#             */
/*   Updated: 2020/03/06 20:23:34 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>

int			is_whitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

int			is_plusminus(char c)
{
	if (c == '-' || c == '+')
		return (1);
	else
		return (0);
}

int			is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

double		ft_atoi_decimal(char *str)
{
	double	value_dec;
	int		dec_order;

	value_dec = 0;
	dec_order = 0;
	if (*str == '.')
	{
		str++;
		while (*str >= '0' && *str <= '9')
		{
			value_dec *= 10;
			value_dec += 48 - *str;
			dec_order++;
			str++;
		}
		value_dec = (value_dec >= 0) ? value_dec : -value_dec;
	}
	return (value_dec / pow(10, dec_order));
}

double		ft_atoi_double(char *str)
{
	double	value;
	int		isneg;

	value = 0;
	isneg = 0;
	while (is_whitespace(*str))
		str++;
	if (is_plusminus(*str))
	{
		isneg = (*str == '-' ? 1 : 0);
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		value *= 10;
		value += 48 - *str;
		str++;
	}
	value = -value + ft_atoi_decimal(str);
	value = isneg ? -value : value;
	return (value);
}
