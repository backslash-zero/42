/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 17:42:35 by cmeunier          #+#    #+#             */
/*   Updated: 2019/11/28 17:09:52 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int		ft_putnbr_len(int nb)
{
	int		len;

	len = 1;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
		len++;
	}
	if (nb <= 9 && nb > 0)
		ft_putchar(nb + '0');
	else if (nb > 0)
	{
		len += ft_putnbr_len(nb / 10);
		ft_putnbr_len(nb % 10);
	}
	else if (nb == 0)
		ft_putchar('0');
	return (len);
}
