/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_print_other.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 12:57:32 by cmeunier          #+#    #+#             */
/*   Updated: 2019/12/09 16:33:09 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

void	print_u(t_ftprint *p)
{
	unsigned int	nb;
	char			*str;

	nb = va_arg(p->list, unsigned int);
	ft_get_number_len_u(p, nb, 10);
	str = ft_number_str_u(nb, p, 10, "0123456789");
	p->arg_len = p->nb_len;
	ft_tests_checks(p);
	ft_putstr(str);
	p->count += p->arg_len;
	free(str);
}

void	print_x_low(t_ftprint *p)
{
	unsigned int	nb;
	char			*str;

	nb = va_arg(p->list, unsigned int);
	ft_get_number_len_u(p, nb, 16);
	str = ft_number_str_u(nb, p, 16, "0123456789abcdef");
	p->arg_len = p->nb_len;
	ft_tests_checks(p);
	ft_putstr(str);
	p->count += p->arg_len;
	free(str);
}

void	print_x_up(t_ftprint *p)
{
	unsigned int	nb;
	char			*str;

	nb = va_arg(p->list, unsigned int);
	ft_get_number_len_u(p, nb, 16);
	str = ft_number_str_u(nb, p, 16, "0123456789ABCDEF");
	p->arg_len = p->nb_len;
	ft_tests_checks(p);
	ft_putstr(str);
	p->count += p->arg_len;
	free(str);
}
