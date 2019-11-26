/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 11:37:06 by cmeunier          #+#    #+#             */
/*   Updated: 2019/11/26 11:37:08 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	//Print str
	ft_printf("Printf:	%s, %s!\n", "Hello", "world");
	printf("Printf:	%s, %s!\n", "Hello", "world");
	return (0);
}