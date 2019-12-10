/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_print_d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 16:32:58 by cmeunier          #+#    #+#             */
/*   Updated: 2019/12/10 19:53:15 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

void	print_d_handle_flags(t_ftprint *p)
{
	if (p->flag_precision && p->field_precision > p->nb_len)
		p->arg_len = p->field_precision;
	if (p->nb_neg && p->flag_zero)
		ft_putchar('-');
	if (!p->flag_minus)
		ft_print_field_width(p);
	if (p->nb_neg && !(p->flag_zero))
		ft_putchar('-');
	if (!p->field_width)
		p->field_precision++;
	if (p->field_precision > p->nb_len && p->flag_precision)
		print_d_precision(p);
}

void	print_d_negative(t_ftprint *p, int nb)
{
	char	*str;

	p->nb_neg = 1;
	nb = -nb;
	ft_get_number_len(p, nb, 10);
	str = ft_number_str(nb, p);
	p->nb_len += 1;
	p->arg_len = p->nb_len;
	print_d_handle_flags(p);
	ft_putstr(str);
	free(str);
	p->count += p->arg_len;
	if (p->flag_minus)
		ft_print_field_width(p);
}

void	print_d_precision(t_ftprint *p)
{
	while (p->field_precision > p->nb_len)
	{
		ft_putchar('0');
		//p->count += 1;
		p->field_precision--;
	}
}

void	print_d_intmin(t_ftprint *p)
{
	p->nb_neg = 1;
	p->nb_len = 11;
	p->arg_len = p->nb_len;
	print_d_handle_flags(p);
	ft_putstr("2147483648");
	p->count += 11;
	if (p->flag_minus)
		ft_print_field_width(p);
}

void	print_d(t_ftprint *p)
{
	int		nb;
	char	*str;

	nb = va_arg(p->list, int);
	if (p->flag_precision)
		p->flag_zero = 0;
	if (nb == -2147483648)
		print_d_intmin(p);
	else if (nb < 0)
		print_d_negative(p, nb);
	else
	{
		ft_get_number_len(p, nb, 10);
		str = ft_number_str(nb, p);
		p->arg_len = p->nb_len;
		print_d_handle_flags(p);
		ft_putstr(str);
		free(str);
		p->count += p->arg_len;
		if (p->flag_minus)
			ft_print_field_width(p);
	}
}
