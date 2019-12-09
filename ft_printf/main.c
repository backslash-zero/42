/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 11:37:06 by cmeunier          #+#    #+#             */
/*   Updated: 2019/12/09 15:19:48 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <string.h>
#include <limits.h>

static void	test_s(void)
{
	char *str = "Celestin";

	printf("##########################################\n");
	printf("###############   s TEST   ###############\n");
	printf("##########################################\n");
	printf("---- Test no /%% && no flags ----\n");
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Hello\n"), ft_printf("Hello\n"));
	printf("\n\n");
	printf("---- Test 1 /%% with 1s && no flags ----\n");
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Hello %s\n", "Célestin"), ft_printf("Hello %s\n", "Célestin"));
	printf("\n\n");
	printf("---- Test 10 /%% with 20s && no flags ----\n");
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Hello %s%s%s%s%s%s%s%s%s%s\n", "Célestin1", "Célestin2", "Célestin3", "Célestin4", "Célestin5", "Célestin6", "Célestin7", "Célestin8", "next one is empty", ""), ft_printf("Hello %s%s%s%s%s%s%s%s%s%s\n", "Célestin1", "Célestin2", "Célestin3", "Célestin4", "Célestin5", "Célestin6", "Célestin7", "Célestin8", "next one is empty", ""));
	printf("\n\n");
	/* printf("---- Test 1 s with 0 FLAG: %%0s ----\n"); // UNDEFINED BEHAVIOUR
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Hello %0s\n", str), ft_printf("Hello %0s\n", str));
	printf("\n\n");
	printf("---- Test 1 s with 0 FLAG: %%00s to %%010s ----\n"); // UNDEFINED BEHAVIOUR
	printf("Return printf: %%s00	%d\nReturn ft_printf:	%d\n ",printf("Hello: %00s\n", str), ft_printf("Hello: %00s\n", str));
	printf("\n\n");
	printf("Return printf: %%s01	%d\nReturn ft_printf:	%d\n ",printf("Hello: %01s\n", str), ft_printf("Hello: %01s\n", str));
	printf("\n\n");
	printf("Return printf: %%s02	%d\nReturn ft_printf:	%d\n ",printf("Hello: %02s\n", str), ft_printf("Hello: %02s\n", str));
	printf("\n\n");
	printf("Return printf: %%s03	%d\nReturn ft_printf:	%d\n ",printf("Hello: %03s\n", str), ft_printf("Hello: %03s\n", str));
	printf("\n\n");
	printf("Return printf: %%s04	%d\nReturn ft_printf:	%d\n ",printf("Hello: %04s\n", str), ft_printf("Hello: %04s\n", str));
	printf("\n\n");
	printf("Return printf: %%s05	%d\nReturn ft_printf:	%d\n ",printf("Hello: %05s\n", str), ft_printf("Hello: %05s\n", str));
	printf("\n\n");
	printf("Return printf: %%s06	%d\nReturn ft_printf:	%d\n ",printf("Hello: %06s\n", str), ft_printf("Hello: %06s\n", str));
	printf("\n\n");
	printf("Return printf: %%s07	%d\nReturn ft_printf:	%d\n ",printf("Hello: %07s\n", str), ft_printf("Hello: %07s\n", str));
	printf("\n\n");
	printf("Return printf: %%s08	%d\nReturn ft_printf:	%d\n ",printf("Hello: %08s\n", str), ft_printf("Hello: %08s\n", str));
	printf("\n\n");
	printf("Return printf: %%s09	%d\nReturn ft_printf:	%d\n ",printf("Hello: %09s\n", str), ft_printf("Hello: %09s\n", str));
	printf("\n\n");
	printf("Return printf: %%s010	%d\nReturn ft_printf:	%d\n",printf("Hello: %010s\n", str), ft_printf("Hello: %010s\n", str));
	printf("\n\n"); */
/* 	printf("---- Test 1 s with NO FLAG: %%0s to %%10s ----\n"); // UNDEFINED BEHAVIOUR
	printf("Return printf: %%s00	%d\nReturn ft_printf:	%d\n ",printf("Hello: %0s\n", str), ft_printf("Hello: %0s\n", str)); // UNDEFINED BEHAVIOUR
	printf("\n\n"); */
	printf("Return printf: %%s01	%d\nReturn ft_printf:	%d\n ",printf("Hello: %1s\n", str), ft_printf("Hello: %1s\n", str));
	printf("\n\n");
	printf("Return printf: %%s02	%d\nReturn ft_printf:	%d\n ",printf("Hello: %2s\n", str), ft_printf("Hello: %2s\n", str));
	printf("\n\n");
	printf("Return printf: %%s03	%d\nReturn ft_printf:	%d\n ",printf("Hello: %3s\n", str), ft_printf("Hello: %3s\n", str));
	printf("\n\n");
	printf("Return printf: %%s04	%d\nReturn ft_printf:	%d\n ",printf("Hello: %4s\n", str), ft_printf("Hello: %4s\n", str));
	printf("\n\n");
	printf("Return printf: %%s05	%d\nReturn ft_printf:	%d\n ",printf("Hello: %5s\n", str), ft_printf("Hello: %5s\n", str));
	printf("\n\n");
	printf("Return printf: %%s06	%d\nReturn ft_printf:	%d\n ",printf("Hello: %6s\n", str), ft_printf("Hello: %6s\n", str));
	printf("\n\n");
	printf("Return printf: %%s07	%d\nReturn ft_printf:	%d\n ",printf("Hello: %7s\n", str), ft_printf("Hello: %7s\n", str));
	printf("\n\n");
	printf("Return printf: %%s08	%d\nReturn ft_printf:	%d\n ",printf("Hello: %8s\n", str), ft_printf("Hello: %8s\n", str));
	printf("\n\n");
	printf("Return printf: %%s09	%d\nReturn ft_printf:	%d\n ",printf("Hello: %9s\n", str), ft_printf("Hello: %9s\n", str));
	printf("\n\n");
	printf("Return printf: %%s010	%d\nReturn ft_printf:	%d\n ",printf("Hello: %10s\n", str), ft_printf("Hello: %10s\n", str));
	printf("\n\n");
	printf("\n\n");
 	printf("---- Test precision: ----\n");
	printf("Return printf: %%.0s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.0s\n", str), ft_printf("Hello: %.0s\n", str));
	printf("Return printf: %%.1s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.1s\n", str), ft_printf("Hello: %.1s\n", str));
	printf("Return printf: %%.2s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.2s\n", str), ft_printf("Hello: %.2s\n", str));
	printf("Return printf: %%.3s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.3s\n", str), ft_printf("Hello: %.3s\n", str));
	printf("Return printf: %%.4s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.4s\n", str), ft_printf("Hello: %.4s\n", str));
	printf("Return printf: %%.5s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.5s\n", str), ft_printf("Hello: %.5s\n", str));
	printf("Return printf: %%.6s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.6s\n", str), ft_printf("Hello: %.6s\n", str));
	printf("Return printf: %%.7s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.7s\n", str), ft_printf("Hello: %.7s\n", str));
	printf("Return printf: %%.8s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.8s\n", str), ft_printf("Hello: %.8s\n", str));
	printf("Return printf: %%.9s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.9s\n", str), ft_printf("Hello: %.9s\n", str));
	printf("Return printf: %%.0s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.0s\n", str), ft_printf("Hello: %.0s\n", str));
	printf("Return printf: %%.1s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.1s\n", str), ft_printf("Hello: %.1s\n", str));
	printf("Return printf: %%.2s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.2s\n", str), ft_printf("Hello: %.2s\n", str));
	printf("Return printf: %%.3s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.3s\n", str), ft_printf("Hello: %.3s\n", str));
	printf("Return printf: %%.4s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.4s\n", str), ft_printf("Hello: %.4s\n", str));
	printf("Return printf: %%.5s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.5s\n", str), ft_printf("Hello: %.5s\n", str));
	printf("Return printf: %%.6s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.6s\n", str), ft_printf("Hello: %.6s\n", str));
	printf("Return printf: %%.7s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.7s\n", str), ft_printf("Hello: %.7s\n", str));
	printf("Return printf: %%.8s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.8s\n", str), ft_printf("Hello: %.8s\n", str));
	printf("Return printf: %%.9s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.9s\n", str), ft_printf("Hello: %.9s\n", str));
	printf("\n\n");
	printf("Return printf: %%.0s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.0s|end\n", str), ft_printf("Hello: %.0s|end\n", str));
	printf("\n\n");
	printf("Return printf: %%.s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.s|end\n", str), ft_printf("Hello: %.s|end\n", str));
	printf("\n\n");
	printf("Return printf: %%20.20s	%d\nReturn ft_printf:	%d\n",printf("Hello: %20.20s|end\n", str), ft_printf("Hello: %20.20s|end\n", str));
	printf("\n\n");
	printf("Return printf: %%10.10s	%d\nReturn ft_printf:	%d\n",printf("Hello: %10.10s|end\n", str), ft_printf("Hello: %10.10s|end\n", str));
	printf("\n\n");
	printf("Return printf: %%5.5s	%d\nReturn ft_printf:	%d\n",printf("Hello: %5.5s|end\n", str), ft_printf("Hello: %5.5s|end\n", str));
	printf("\n\n");
	printf("Return printf: %%1.1s	%d\nReturn ft_printf:	%d\n", printf("Hello: %1.1s|end\n", str), ft_printf("Hello: %1.1s|end\n", str));
	printf("\n\n");
	printf("Return printf: %%-10.10s	%d\nReturn ft_printf:	%d\n",printf("Hello: %-10.10s|end\n", str), ft_printf("Hello: %-10.10s|end\n", str));
	printf("\n\n");
	printf("Return printf: %%-1.10s	%d\nReturn ft_printf:	%d\n",printf("Hello: %-1.10s|end\n", str), ft_printf("Hello: %-1.10s|end\n", str));
	printf("\n\n");
	printf("Return printf: %%-5.10s	%d\nReturn ft_printf:	%d\n",printf("Hello: %-5.10s|end\n", str), ft_printf("Hello: %-5.10s|end\n", str));
	printf("\n\n");
	printf("Return printf: %%*.5s	%d\nReturn ft_printf:	%d\n",printf("Hello: %*.5s|end\n", 5, str), ft_printf("Hello: %*.5s|end\n", 5, str));
	printf("\n\n");
	printf("Return printf: %%-*.5s	%d\nReturn ft_printf:	%d\n",printf("Hello: %-*.5s|end\n", 5, str), ft_printf("Hello: %-*.5s|end\n", 5, str));
	printf("\n\n");
	printf("Return printf: %%5.*s	%d\nReturn ft_printf:	%d\n",printf("Hello: %5.*s|end\n", 15, str), ft_printf("Hello: %5.*s|end\n", 15, str));
	printf("\n\n");
	printf("Return printf: %%5.*s	%d\nReturn ft_printf:	%d\n",printf("Hello: %5.*s|end\n", 5, str), ft_printf("Hello: %5.*s|end\n", 5, str));
	printf("\n\n");
	printf("Return printf: %%*.*s	%d\nReturn ft_printf:	%d\n",printf("Hello: %-*.*s|end\n", -10, 5, str), ft_printf("Hello: %-*.*s|end\n", -10, 5, str));
	printf("\n\n");
	printf("Return printf: %%*s	%d\nReturn ft_printf:	%d\n",printf("Hello: %*s|end\n", 27, str), ft_printf("Hello: %*s|end\n", 27, str));
	printf("\n\n");
	printf("Return printf: %%27s	%d\nReturn ft_printf:	%d\n",printf("Hello: %27s|end\n", str), ft_printf("Hello: %27s|end\n", str));
	printf("\n\n");
	printf("Return printf: %%*.5s	%d\nReturn ft_printf:	%d\n", printf("Hello: %*.5s|end\n", 15, str), ft_printf("Hello: %*.5s|end\n", 15, str));
	printf("\n\n");
	printf("Return printf: %%15.5s	%d\nReturn ft_printf:	%d\n", printf("Hello: %15.5s|end\n", str), ft_printf("Hello: %15.5s|end\n", str));
	printf("\n\n");
	printf("Return printf: %%3.3s	%d\nReturn ft_printf:	%d\n", printf("Hello: %3.3s|end\n", str), ft_printf("Hello: %3.3s|end\n", str));
	printf("\n\n");
	printf("Return printf: %%8.8s	%d\nReturn ft_printf:	%d\n", printf("Hello: %8.8s|end\n", str), ft_printf("Hello: %8.8s|end\n", str));
	printf("\n\n");
	printf("Return printf: %%9.9s	%d\nReturn ft_printf:	%d\n", printf("Hello: %9.9s|end\n", str), ft_printf("Hello: %9.9s|end\n", str));
	printf("\n\n");
	printf("Return printf: %%10.10s	%d\nReturn ft_printf:	%d\n", printf("Hello: %10.10s|end\n", str), ft_printf("Hello: %10.10s|end\n", str));
	printf("\n\n");
	printf("Return printf: %%15s	%d\nReturn ft_printf:	%d\n", printf("Hello: %15s|end\n", str), ft_printf("Hello: %15s|end\n", str));
	printf("\n\n");
	printf("Return printf: %%*.*s	%d\nReturn ft_printf:	%d\n",printf("Hello: %*.*s|end\n", 10, 5, str), ft_printf("Hello: %*.*s|end\n", 10, 5, str));
	printf("\n\n");
	printf("Return printf: %%*.*s	%d\nReturn ft_printf:	%d\n",printf("Hello: %*.*s|end\n", 10, 5, str), ft_printf("Hello: %*.*s|end\n", 10, 5, str));
	printf("\n\n");
	printf("Return printf: %%*.*s	%d\nReturn ft_printf:	%d\n",printf("Hello: %10.*s|end\n", 5, str), ft_printf("Hello: %10.*s|end\n", 5, str));
	printf("\n\n");
	printf("Return printf: %%*.*s	%d\nReturn ft_printf:	%d\n",printf("Hello: %10.*s|end\n", 5, str), ft_printf("Hello: %10.*s|end\n", 5, str));
	printf("\n\n");
	printf("!eturn printf: %%*.*s	%d\nReturn ft_printf:	%d\n",printf("Hello: %*.*s|end\n", -10, -5, str), ft_printf("Hello: %*.*s|end\n", -10, -5, str));
	printf("\n\n");
	printf("!eturn printf: %%-*.*s	%d\nReturn ft_printf:	%d\n",printf("Hello: %-*.*s|end\n", 10, -5, str), ft_printf("Hello: %-*.*s|end\n", 10, -5, str));
	printf("\n\n");
	printf("!eturn printf: %%*.*s	%d\nReturn ft_printf:	%d\n",printf("Hello: %-10.*s|end\n", -5, str), ft_printf("Hello: %-10.*s|end\n", -5, str));
	printf("\n\n");
	printf("!eturn printf: %%-*.*s	%d\nReturn ft_printf:	%d\n",printf("Hello: %10.*s|end\n", -5, str), ft_printf("Hello: %10.*s|end\n", -5, str));
	printf("\n\n");
	printf("\n\n");
	printf("\n\n");
	printf("\n\n");
}

static void	test_c(void)
{
	char c = 'C';
	printf("##########################################\n");
	printf("###############   c TEST   ###############\n");
	printf("##########################################\n");
	printf("---- Test 1 /%% with 1c && no flags ----\n");
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Hello %c\n", 'C'), ft_printf("Hello %c\n", 'C'));
	printf("\n\n");
	printf("---- Test 1 /%% with 5c && no flags ----\n");
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Hello %c%c%c%c%c\n", 'C', 'C', 'C', 'C', 'C'), ft_printf("Hello %c%c%c%c%c\n", 'C', 'C', 'C', 'C', 'C'));
	printf("\n\n");
	/* printf("---- Test 1 d with 0 FLAG: %%c ----\n"); // UNDEFINED BEHAVIOUR
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Hello %0c\n", c), ft_printf("Hello %0c\n", c));
	printf("\n\n");
	printf("---- Test 1 d with 0 FLAG: %%00c to %%010c ----\n"); // UNDEFINED BEHAVIOUR
	printf("Return printf: %%c00	%d\nReturn ft_printf:	%d\n ",printf("Hello: %00c\n", c), ft_printf("Hello: %00c\n", c));
	printf("\n\n");
	printf("Return printf: %%c01	%d\nReturn ft_printf:	%d\n ",printf("Hello: %01c\n", c), ft_printf("Hello: %01c\n", c));
	printf("\n\n");
	printf("Return printf: %%c02	%d\nReturn ft_printf:	%d\n ",printf("Hello: %02c\n", c), ft_printf("Hello: %02c\n", c));
	printf("\n\n");
	printf("Return printf: %%c03	%d\nReturn ft_printf:	%d\n ",printf("Hello: %03c\n", c), ft_printf("Hello: %03c\n", c));
	printf("\n\n");
	printf("Return printf: %%c04	%d\nReturn ft_printf:	%d\n ",printf("Hello: %04c\n", c), ft_printf("Hello: %04c\n", c));
	printf("\n\n");
	printf("Return printf: %%c05	%d\nReturn ft_printf:	%d\n ",printf("Hello: %05c\n", c), ft_printf("Hello: %05c\n", c));
	printf("\n\n");
	printf("Return printf: %%c06	%d\nReturn ft_printf:	%d\n ",printf("Hello: %06c\n", c), ft_printf("Hello: %06c\n", c));
	printf("\n\n");
	printf("Return printf: %%c07	%d\nReturn ft_printf:	%d\n ",printf("Hello: %07c\n", c), ft_printf("Hello: %07c\n", c));
	printf("\n\n");
	printf("Return printf: %%c08	%d\nReturn ft_printf:	%d\n ",printf("Hello: %08c\n", c), ft_printf("Hello: %08c\n", c));
	printf("\n\n");
	printf("Return printf: %%c09	%d\nReturn ft_printf:	%d\n ",printf("Hello: %09c\n", c), ft_printf("Hello: %09c\n", c));
	printf("\n\n");
	printf("Return printf: %%c010	%d\nReturn ft_printf:	%d\n",printf("Hello: %010c\n", c), ft_printf("Hello: %010c\n", c));
	printf("\n\n");
	printf("---- Test 1 d with NO FLAG: %%0c to %%10c ----\n"); // UNDEFINED BEHAVIOUR
	printf("Return printf: %%c00	%d\nReturn ft_printf:	%d\n ",printf("Hello: %0c\n", c), ft_printf("Hello: %0c\n", c));
	printf("\n\n"); */
	printf("Return printf: %%c01	%d\nReturn ft_printf:	%d\n ",printf("Hello: %1c\n", c), ft_printf("Hello: %1c\n", c));
	printf("\n\n");
	printf("Return printf: %%c02	%d\nReturn ft_printf:	%d\n ",printf("Hello: %2c\n", c), ft_printf("Hello: %2c\n", c));
	printf("\n\n");
	printf("Return printf: %%c03	%d\nReturn ft_printf:	%d\n ",printf("Hello: %3c\n", c), ft_printf("Hello: %3c\n", c));
	printf("\n\n");
	printf("Return printf: %%c04	%d\nReturn ft_printf:	%d\n ",printf("Hello: %4c\n", c), ft_printf("Hello: %4c\n", c));
	printf("\n\n");
	printf("Return printf: %%c05	%d\nReturn ft_printf:	%d\n ",printf("Hello: %5c\n", c), ft_printf("Hello: %5c\n", c));
	printf("\n\n");
	printf("Return printf: %%c06	%d\nReturn ft_printf:	%d\n ",printf("Hello: %6c\n", c), ft_printf("Hello: %6c\n", c));
	printf("\n\n");
	printf("Return printf: %%c07	%d\nReturn ft_printf:	%d\n ",printf("Hello: %7c\n", c), ft_printf("Hello: %7c\n", c));
	printf("\n\n");
	printf("Return printf: %%c08	%d\nReturn ft_printf:	%d\n ",printf("Hello: %8c\n", c), ft_printf("Hello: %8c\n", c));
	printf("\n\n");
	printf("Return printf: %%c09	%d\nReturn ft_printf:	%d\n ",printf("Hello: %9c\n", c), ft_printf("Hello: %9c\n", c));
	printf("\n\n");
	printf("Return printf: %%c010	%d\nReturn ft_printf:	%d\n",printf("Hello: %10c\n", c), ft_printf("Hello: %10c\n", c));
	printf("\n\n");
	printf("\n\n");
	printf("\n\n");
	printf("\n\n");
}

static void	test_d(void)
{
		int a = 10;

	
	printf("##########################################\n");
	printf("###############   d TEST   ##############\n");
	printf("##########################################\n");	
	printf("---- Test 1 d ----\n");
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Hello %d\n", a), ft_printf("Hello %d\n", a));
	printf("\n\n");
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Hello %d\n", 1), ft_printf("Hello %d\n", 1));
	printf("\n\n");
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Hello %d\n", 0), ft_printf("Hello %d\n", 0));
	printf("\n\n");
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Hello %d\n", -77), ft_printf("Hello %d\n", -77));
	printf("\n\n");
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Hello %d\n", -120000), ft_printf("Hello %d\n", -120000));
	printf("\n\n");
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Hello %d\n", 666666666), ft_printf("Hello %d\n", 666666666));
	printf("\n\n");
	printf("---- Test 1 d with 0 FLAG: %%0d ----\n");
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Hello %0d\n", a), ft_printf("Hello %0d\n", a));
	printf("\n\n");
	printf("---- Test 1 d with 0 FLAG: %%00d to %%010d ----\n");
	printf("Return printf: %%d00	%d\nReturn ft_printf:	%d\n ",printf("Hello: %00d\n", 55), ft_printf("Hello: %00d\n", 55));
	printf("\n\n");
	printf("Return printf: %%d01	%d\nReturn ft_printf:	%d\n ",printf("Hello: %01d\n", 55), ft_printf("Hello: %01d\n", 55));
	printf("\n\n");
	printf("Return printf: %%d02	%d\nReturn ft_printf:	%d\n ",printf("Hello: %02d\n", 55), ft_printf("Hello: %02d\n", 55));
	printf("\n\n");
	printf("Return printf: %%d03	%d\nReturn ft_printf:	%d\n ",printf("Hello: %03d\n", 55), ft_printf("Hello: %03d\n", 55));
	printf("\n\n");
	printf("Return printf: %%d04	%d\nReturn ft_printf:	%d\n ",printf("Hello: %04d\n", 55), ft_printf("Hello: %04d\n", 55));
	printf("\n\n");
	printf("Return printf: %%d05	%d\nReturn ft_printf:	%d\n ",printf("Hello: %05d\n", 55), ft_printf("Hello: %05d\n", 55));
	printf("\n\n");
	printf("Return printf: %%d06	%d\nReturn ft_printf:	%d\n ",printf("Hello: %06d\n", 55), ft_printf("Hello: %06d\n", 55));
	printf("\n\n");
	printf("Return printf: %%d07	%d\nReturn ft_printf:	%d\n ",printf("Hello: %07d\n", 55), ft_printf("Hello: %07d\n", 55));
	printf("\n\n");
	printf("Return printf: %%d08	%d\nReturn ft_printf:	%d\n ",printf("Hello: %08d\n", 55), ft_printf("Hello: %08d\n", 55));
	printf("\n\n");
	printf("Return printf: %%d09	%d\nReturn ft_printf:	%d\n ",printf("Hello: %09d\n", 55), ft_printf("Hello: %09d\n", 55));
	printf("\n\n");
	printf("Return printf: %%d010	%d\nReturn ft_printf:	%d\n",printf("Hello: %010d\n", 55), ft_printf("Hello: %010d\n", 55));
	printf("\n\n");
	printf("---- Test 1 d with NO FLAG: %%0d to %%10d ----\n");
	printf("Return printf: %%d00	%d\nReturn ft_printf:	%d\n ",printf("Hello: %0d\n", 55), ft_printf("Hello: %0d\n", 55));
	printf("\n\n");
	printf("Return printf: %%d01	%d\nReturn ft_printf:	%d\n ",printf("Hello: %1d\n", 55), ft_printf("Hello: %1d\n", 55));
	printf("\n\n");
	printf("Return printf: %%d02	%d\nReturn ft_printf:	%d\n ",printf("Hello: %2d\n", 55), ft_printf("Hello: %2d\n", 55));
	printf("\n\n");
	printf("Return printf: %%d03	%d\nReturn ft_printf:	%d\n ",printf("Hello: %3d\n", 55), ft_printf("Hello: %3d\n", 55));
	printf("\n\n");
	printf("Return printf: %%d04	%d\nReturn ft_printf:	%d\n ",printf("Hello: %4d\n", 55), ft_printf("Hello: %4d\n", 55));
	printf("\n\n");
	printf("Return printf: %%d05	%d\nReturn ft_printf:	%d\n ",printf("Hello: %5d\n", 55), ft_printf("Hello: %5d\n", 55));
	printf("\n\n");
	printf("Return printf: %%d06	%d\nReturn ft_printf:	%d\n ",printf("Hello: %6d\n", 55), ft_printf("Hello: %6d\n", 55));
	printf("\n\n");
	printf("Return printf: %%d07	%d\nReturn ft_printf:	%d\n ",printf("Hello: %7d\n", 55), ft_printf("Hello: %7d\n", 55));
	printf("\n\n");
	printf("Return printf: %%d08	%d\nReturn ft_printf:	%d\n ",printf("Hello: %8d\n", 55), ft_printf("Hello: %8d\n", 55));
	printf("\n\n");
	printf("Return printf: %%d09	%d\nReturn ft_printf:	%d\n ",printf("Hello: %9d\n", 55), ft_printf("Hello: %9d\n", 55));
	printf("\n\n");
	printf("Return printf: %%d010	%d\nReturn ft_printf:	%d\n",printf("Hello: %10d\n", 55), ft_printf("Hello: %10d\n", 55));
	printf("\n\n");
	printf("Return printf: %%d00	%d\nReturn ft_printf:	%d\n ",printf("Hello: %0d\n", -55), ft_printf("Hello: %0d\n", -55));
	printf("\n\n");
	printf("Return printf: %%d01	%d\nReturn ft_printf:	%d\n ",printf("Hello: %1d\n", -55), ft_printf("Hello: %1d\n", -55));
	printf("\n\n");
	printf("Return printf: %%d02	%d\nReturn ft_printf:	%d\n ",printf("Hello: %2d\n", -55), ft_printf("Hello: %2d\n", -55));
	printf("\n\n");
	printf("Return printf: %%d03	%d\nReturn ft_printf:	%d\n ",printf("Hello: %3d\n", -55), ft_printf("Hello: %3d\n", -55));
	printf("\n\n");
	printf("Return printf: %%d04	%d\nReturn ft_printf:	%d\n ",printf("Hello: %4d\n", -55), ft_printf("Hello: %4d\n", -55));
	printf("\n\n");
	printf("Return printf: %%d05	%d\nReturn ft_printf:	%d\n ",printf("Hello: %5d\n", -55), ft_printf("Hello: %5d\n", -55));
	printf("\n\n");
	printf("Return printf: %%d06	%d\nReturn ft_printf:	%d\n ",printf("Hello: %6d\n", -55), ft_printf("Hello: %6d\n", -55));
	printf("\n\n");
	printf("Return printf: %%d07	%d\nReturn ft_printf:	%d\n ",printf("Hello: %7d\n", -55), ft_printf("Hello: %7d\n", -55));
	printf("\n\n");
	printf("Return printf: %%d08	%d\nReturn ft_printf:	%d\n ",printf("Hello: %8d\n", -55), ft_printf("Hello: %8d\n", -55));
	printf("\n\n");
	printf("Return printf: %%d09	%d\nReturn ft_printf:	%d\n ",printf("Hello: %9d\n", -55), ft_printf("Hello: %9d\n", -55));
	printf("\n\n");
	printf("Return printf: %%d010	%d\nReturn ft_printf:	%d\n",printf("Hello: %10d\n", -55), ft_printf("Hello: %10d\n", -55));
	printf("\n\n");
	printf("---- Test precision 1: ----\n");
	printf("Return printf: %%.0s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.0d\n", 55), ft_printf("Hello: %.0d\n", 55));
	printf("Return printf: %%.1s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.1d\n", 55), ft_printf("Hello: %.1d\n", 55));
	printf("Return printf: %%.2s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.2d\n", 55), ft_printf("Hello: %.2d\n", 55));
	printf("Return printf: %%.3s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.3d\n", 55), ft_printf("Hello: %.3d\n", 55));
	printf("Return printf: %%.4s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.4d\n", 55), ft_printf("Hello: %.4d\n", 55));
	printf("Return printf: %%.5s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.5d\n", 55), ft_printf("Hello: %.5d\n", 55));
	printf("Return printf: %%.6s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.6d\n", 55), ft_printf("Hello: %.6d\n", 55));
	printf("Return printf: %%.7s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.7d\n", 55), ft_printf("Hello: %.7d\n", 55));
	printf("Return printf: %%.8s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.8d\n", 55), ft_printf("Hello: %.8d\n", 55));
	printf("Return printf: %%.9s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.9d\n", 55), ft_printf("Hello: %.9d\n", 55));
	printf("Return printf: %%.0s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.0d\n", -55), ft_printf("Hello: %.0d\n", -55));
	printf("Return printf: %%.1s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.1d\n", -55), ft_printf("Hello: %.1d\n", -55));
	printf("Return printf: %%.2s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.2d\n", -55), ft_printf("Hello: %.2d\n", -55));
	printf("Return printf: %%.3s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.3d\n", -55), ft_printf("Hello: %.3d\n", -55));
	printf("Return printf: %%.4s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.4d\n", -55), ft_printf("Hello: %.4d\n", -55));
	printf("Return printf: %%.5s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.5d\n", -55), ft_printf("Hello: %.5d\n", -55));
	printf("Return printf: %%.6s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.6d\n", -55), ft_printf("Hello: %.6d\n", -55));
	printf("Return printf: %%.7s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.7d\n", -55), ft_printf("Hello: %.7d\n", -55));
	printf("Return printf: %%.8s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.8d\n", -55), ft_printf("Hello: %.8d\n", -55));
	printf("Return printf: %%.9s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.9d\n", -55), ft_printf("Hello: %.9d\n", -55));
	printf("Return printf: %%0.s	%d\nReturn ft_printf:	%d\n",printf("Hello: %0.d\n", 55), ft_printf("Hello: %0.d\n", 55));
	printf("Return printf: %%1.s	%d\nReturn ft_printf:	%d\n",printf("Hello: %1.d\n", 55), ft_printf("Hello: %1.d\n", 55));
	printf("Return printf: %%2.s	%d\nReturn ft_printf:	%d\n",printf("Hello: %2.d\n", 55), ft_printf("Hello: %2.d\n", 55));
	printf("Return printf: %%3.s	%d\nReturn ft_printf:	%d\n",printf("Hello: %3.d\n", 55), ft_printf("Hello: %3.d\n", 55));
	printf("Return printf: %%4.s	%d\nReturn ft_printf:	%d\n",printf("Hello: %4.d\n", 55), ft_printf("Hello: %4.d\n", 55));
	printf("Return printf: %%5.s	%d\nReturn ft_printf:	%d\n",printf("Hello: %5.d\n", 55), ft_printf("Hello: %5.d\n", 55));
	printf("Return printf: %%6.s	%d\nReturn ft_printf:	%d\n",printf("Hello: %6.d\n", 55), ft_printf("Hello: %6.d\n", 55));
	printf("Return printf: %%7.s	%d\nReturn ft_printf:	%d\n",printf("Hello: %7.d\n", 55), ft_printf("Hello: %7.d\n", 55));
	printf("Return printf: %%8.s	%d\nReturn ft_printf:	%d\n",printf("Hello: %8.d\n", 55), ft_printf("Hello: %8.d\n", 55));
	printf("Return printf: %%9.s	%d\nReturn ft_printf:	%d\n",printf("Hello: %9.d\n", 55), ft_printf("Hello: %9.d\n", 55));
	printf("Return printf: %%0.s	%d\nReturn ft_printf:	%d\n",printf("Hello: %0.d\n", -55), ft_printf("Hello: %0.d\n", -55));
	printf("Return printf: %%1.s	%d\nReturn ft_printf:	%d\n",printf("Hello: %1.d\n", -55), ft_printf("Hello: %1.d\n", -55));
	printf("Return printf: %%2.s	%d\nReturn ft_printf:	%d\n",printf("Hello: %2.d\n", -55), ft_printf("Hello: %2.d\n", -55));
	printf("Return printf: %%3.s	%d\nReturn ft_printf:	%d\n",printf("Hello: %3.d\n", -55), ft_printf("Hello: %3.d\n", -55));
	printf("Return printf: %%4.s	%d\nReturn ft_printf:	%d\n",printf("Hello: %4.d\n", -55), ft_printf("Hello: %4.d\n", -55));
	printf("Return printf: %%5.s	%d\nReturn ft_printf:	%d\n",printf("Hello: %5.d\n", -55), ft_printf("Hello: %5.d\n", -55));
	printf("Return printf: %%6.s	%d\nReturn ft_printf:	%d\n",printf("Hello: %6.d\n", -55), ft_printf("Hello: %6.d\n", -55));
	printf("Return printf: %%7.s	%d\nReturn ft_printf:	%d\n",printf("Hello: %7.d\n", -55), ft_printf("Hello: %7.d\n", -55));
	printf("Return printf: %%8.s	%d\nReturn ft_printf:	%d\n",printf("Hello: %8.d\n", -55), ft_printf("Hello: %8.d\n", -55));
	printf("Return printf: %%9.s	%d\nReturn ft_printf:	%d\n",printf("Hello: %9.d\n", -55), ft_printf("Hello: %9.d\n", -55));
	printf("Return printf: %%15.s	%d\nReturn ft_printf:	%d\n",printf("Hello: %15.d\n", INT_MIN), ft_printf("Hello: %15.d\n", INT_MIN));
	printf("Return printf: %%15s	%d\nReturn ft_printf:	%d\n",printf("Hello: %15d\n", INT_MIN), ft_printf("Hello: %15d\n", INT_MIN));
	printf("Return printf: %%015s	%d\nReturn ft_printf:	%d\n",printf("Hello: %015d\n", INT_MIN), ft_printf("Hello: %015d\n", INT_MIN));
	printf("Return printf: %%.15s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.15d\n", INT_MIN), ft_printf("Hello: %.15d\n", INT_MIN));
	printf("Return printf: %%15s	%d\nReturn ft_printf:	%d\n",printf("Hello: %15d\n", INT_MIN), ft_printf("Hello: %15d\n", INT_MIN));
	printf("Return printf: %%015s	%d\nReturn ft_printf:	%d\n",printf("Hello: %015d\n", INT_MIN), ft_printf("Hello: %015d\n", INT_MIN));
	printf("\n\n");
	printf("\n\n");
	printf("---- Test precision 2: ----\n");
	printf("\n\n");
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Example:	%%*d	%*d\n", -4, 0), ft_printf("Example:	%%*d	%*d\n", -4, 0));
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Example:	%%*d	%*d\n", 4, 0), ft_printf("Example:	%%*d	%*d\n", 4, 0));
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Example:	%%*d	%*d\n", 0, -666), ft_printf("Example:	%%*d	%*d\n", 0, -666));
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Example:	%%*d	%*d\n", 1, -666), ft_printf("Example:	%%*d	%*d\n", 1, -666));
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Example:	%%*d	%*d\n", 2, -666), ft_printf("Example:	%%*d	%*d\n", 2, -666));
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Example:	%%*d	%*d\n", 3, -666), ft_printf("Example:	%%*d	%*d\n", 3, -666));
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Example:	%%*d	%*d\n", 4, -666), ft_printf("Example:	%%*d	%*d\n", 4, -666));
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Example:	%%*d	%*d\n", 5, -666), ft_printf("Example:	%%*d	%*d\n", 5, -666));
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Example:	%%*d	%*d\n", 6, -666), ft_printf("Example:	%%*d	%*d\n", 6, -666));
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Example:	%%*d	%*d\n", 7, -666), ft_printf("Example:	%%*d	%*d\n", 7, -666));
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Example:	%%*d	%*d\n", 8, -666), ft_printf("Example:	%%*d	%*d\n", 8, -666));
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Example:	%%*d	%*d\n", 9, -666), ft_printf("Example:	%%*d	%*d\n", 9, -666));
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Example:	%%*d	%*d\n", 0, -666), ft_printf("Example:	%%*d	%*d\n", 0, -666));
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Example:	%%*d	%*d\n", 1, -666), ft_printf("Example:	%%*d	%*d\n", 1, -666));
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Example:	%%*d	%*d\n", 2, -666), ft_printf("Example:	%%*d	%*d\n", 2, -666));
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Example:	%%*d	%*d\n", 3, -666), ft_printf("Example:	%%*d	%*d\n", 3, -666));
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Example:	%%*d	%*d\n", 4, -666), ft_printf("Example:	%%*d	%*d\n", 4, -666));
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Example:	%%*d	%*d\n", 5, -666), ft_printf("Example:	%%*d	%*d\n", 5, -666));
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Example:	%%*d	%*d\n", 6, -666), ft_printf("Example:	%%*d	%*d\n", 6, -666));
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Example:	%%*d	%*d\n", 7, -666), ft_printf("Example:	%%*d	%*d\n", 7, -666));
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Example:	%%*d	%*d\n", 8, -666), ft_printf("Example:	%%*d	%*d\n", 8, -666));
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Example:	%%*d	%*d\n", 9, -666), ft_printf("Example:	%%*d	%*d\n", 9, -666));
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Example:	%%*d	%*d\n", 0, 666), ft_printf("Example:	%%*d	%*d\n", 0, 666));
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Example:	%%*d	%*d\n", 1, 666), ft_printf("Example:	%%*d	%*d\n", 1, 666));
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Example:	%%*d	%*d\n", 2, 666), ft_printf("Example:	%%*d	%*d\n", 2, 666));
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Example:	%%*d	%*d\n", 3, 666), ft_printf("Example:	%%*d	%*d\n", 3, 666));
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Example:	%%*d	%*d\n", 4, 666), ft_printf("Example:	%%*d	%*d\n", 4, 666));
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Example:	%%*d	%*d\n", 5, 666), ft_printf("Example:	%%*d	%*d\n", 5, 666));
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Example:	%%*d	%*d\n", 6, 666), ft_printf("Example:	%%*d	%*d\n", 6, 666));
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Example:	%%*d	%*d\n", 7, 666), ft_printf("Example:	%%*d	%*d\n", 7, 666));
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Example:	%%*d	%*d\n", 8, 666), ft_printf("Example:	%%*d	%*d\n", 8, 666));
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Example:	%%*d	%*d\n", 9, 666), ft_printf("Example:	%%*d	%*d\n", 9, 666));
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Example:	%%*d	%*d\n", 0, 666), ft_printf("Example:	%%*d	%*d\n", 0, 666));
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Example:	%%*d	%*d\n", 1, 666), ft_printf("Example:	%%*d	%*d\n", 1, 666));
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Example:	%%*d	%*d\n", 2, 666), ft_printf("Example:	%%*d	%*d\n", 2, 666));
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Example:	%%*d	%*d\n", 3, 666), ft_printf("Example:	%%*d	%*d\n", 3, 666));
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Example:	%%*d	%*d\n", 4, 666), ft_printf("Example:	%%*d	%*d\n", 4, 666));
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Example:	%%*d	%*d\n", 5, 666), ft_printf("Example:	%%*d	%*d\n", 5, 666));
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Example:	%%*d	%*d\n", 6, 666), ft_printf("Example:	%%*d	%*d\n", 6, 666));
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Example:	%%*d	%*d\n", 7, 666), ft_printf("Example:	%%*d	%*d\n", 7, 666));
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Example:	%%*d	%*d\n", 8, 666), ft_printf("Example:	%%*d	%*d\n", 8, 666));
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Example:	%%*d	%*d\n", 9, 666), ft_printf("Example:	%%*d	%*d\n", 9, 666));
	printf("\n\n");
	printf("\n\n");
	printf("---- Test negative: ----\n");
	printf("Return printf: %%*d	%d\nReturn ft_printf: %%*d	%d\n",printf("Example: %*d|End\n", -12, -666), ft_printf("Example: %*d|End\n", -12, -666));
	printf("Return printf: %%*d	%d\nReturn ft_printf: %%*d	%d\n",printf("Example: %*d|End\n", -24, -666), ft_printf("Example: %*d|End\n", -24, -666));
	printf("Return printf: %%*d	%d\nReturn ft_printf: %%*d	%d\n",printf("Example: %*d|End\n", 0, -666), ft_printf("Example: %*d|End\n", 0, -666));
	printf("Return printf: %%*d	%d\nReturn ft_printf: %%*d	%d\n",printf("Example: %*d|End\n", -24, -666), ft_printf("Example: %*d|End\n", -24, -666));
	printf("Return printf: %%-*d	%d\nReturn ft_printf: %%-*d	%d\n",printf("Example: %-*d|End\n", -24, 666), ft_printf("Example: %-*d|End\n", -24, 666));
	printf("Return printf: %%-*.d	%d\nReturn ft_printf: %%-*.d	%d\n",printf("Example: %-*.d|End\n", 8, 666), ft_printf("%%*-.d %-*.d|End\n", 8, 666));
	printf("Return printf: %%0*d	%d\nReturn ft_printf: %%0*d	%d\n",printf("Example: %0*d|End\n", 12, 666), ft_printf("Example: %0*d|End\n", 12, 666));
	printf("Return printf: %%-*d	%d\nReturn ft_printf: %%-*d	%d\n",printf("Example: %-*d|End\n", 8, 666), ft_printf("Example: %-*d|End\n", 8, 666));
	printf("Return printf: %%0*d	%d\nReturn ft_printf: %%0*d	%d\n",printf("Example: %0*d|End\n", 0, 666), ft_printf("Example: %0*d|End\n", 0, 666));
	printf("Return printf: %%*s	%d\nReturn ft_printf: %%*s	%d\n",printf("Example: %*s|End\n", 16, "hello"), ft_printf("Example: %*s|End\n", 16, "hello"));
	printf("Return printf: %%-*s	%d\nReturn ft_printf: %%-*s	%d\n",printf("Example: %-*s|End\n", 16, "hello"), ft_printf("Example: %-*s|End\n", 16, "hello"));
	printf("Return printf: %%*.s	%d\nReturn ft_printf: %%*.s	%d\n",printf("Example: %16.s|End\n", "hello"), ft_printf("Example: %16.s|End\n", "hello"));
	printf("Return printf: %%*.s	%d\nReturn ft_printf: %%*.s	%d\n",printf("Example: %*.s|End\n", 16, "hello"), ft_printf("Example: %*.s|End\n", 16, "hello"));

	printf("\n\n");
	printf("\n\n");
	printf("\n\n");
	printf("\n\n");
}

static void	test_i(void)
{
	int a = 10;

	printf("##########################################\n");
	printf("###############   i TEST   ##############\n");
	printf("##########################################\n");	
	printf("---- Test 1 d ----\n");
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Hello %i\n", a), ft_printf("Hello %i\n", a));
	printf("\n\n");
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Hello %i\n", 1), ft_printf("Hello %i\n", 1));
	printf("\n\n");
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Hello %i\n", 0), ft_printf("Hello %i\n", 0));
	printf("\n\n");
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Hello %i\n", -77), ft_printf("Hello %i\n", -77));
	printf("\n\n");
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Hello %i\n", -120000), ft_printf("Hello %i\n", -120000));
	printf("\n\n");
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Hello %i\n", 666666666), ft_printf("Hello %i\n", 666666666));
	printf("\n\n");
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Hello %i\n", 042), ft_printf("Hello %i\n", 042));
	printf("\n\n");
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Hello %i\n", 0x42), ft_printf("Hello %i\n", 0x42));
	printf("\n\n");
	printf("---- Test 1 d with 0 FLAG: %%0i ----\n");
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Hello %0i\n", a), ft_printf("Hello %0i\n", a));
	printf("\n\n");
	printf("---- Test 1 d with 0 FLAG: %%00i to %%010i ----\n");
	printf("Return printf: %%i00	%d\nReturn ft_printf:	%d\n ",printf("Hello: %00i\n", 55), ft_printf("Hello: %00i\n", 55));
	printf("\n\n");
	printf("Return printf: %%i01	%d\nReturn ft_printf:	%d\n ",printf("Hello: %01i\n", 55), ft_printf("Hello: %01i\n", 55));
	printf("\n\n");
	printf("Return printf: %%i02	%d\nReturn ft_printf:	%d\n ",printf("Hello: %02i\n", 55), ft_printf("Hello: %02i\n", 55));
	printf("\n\n");
	printf("Return printf: %%i03	%d\nReturn ft_printf:	%d\n ",printf("Hello: %03i\n", 55), ft_printf("Hello: %03i\n", 55));
	printf("\n\n");
	printf("Return printf: %%i04	%d\nReturn ft_printf:	%d\n ",printf("Hello: %04i\n", 55), ft_printf("Hello: %04i\n", 55));
	printf("\n\n");
	printf("Return printf: %%i05	%d\nReturn ft_printf:	%d\n ",printf("Hello: %05i\n", 55), ft_printf("Hello: %05i\n", 55));
	printf("\n\n");
	printf("Return printf: %%i06	%d\nReturn ft_printf:	%d\n ",printf("Hello: %06i\n", 55), ft_printf("Hello: %06i\n", 55));
	printf("\n\n");
	printf("Return printf: %%i07	%d\nReturn ft_printf:	%d\n ",printf("Hello: %07i\n", 55), ft_printf("Hello: %07i\n", 55));
	printf("\n\n");
	printf("Return printf: %%i08	%d\nReturn ft_printf:	%d\n ",printf("Hello: %08i\n", 55), ft_printf("Hello: %08i\n", 55));
	printf("\n\n");
	printf("Return printf: %%i09	%d\nReturn ft_printf:	%d\n ",printf("Hello: %09i\n", 55), ft_printf("Hello: %09i\n", 55));
	printf("\n\n");
	printf("Return printf: %%i010	%d\nReturn ft_printf:	%d\n",printf("Hello: %010i\n", 55), ft_printf("Hello: %010i\n", 55));
	printf("\n\n");
	printf("---- Test 1 d with NO FLAG: %%0i to %%10i ----\n");
	printf("Return printf: %%i00	%d\nReturn ft_printf:	%d\n ",printf("Hello: %0i\n", 55), ft_printf("Hello: %0i\n", 55));
	printf("\n\n");
	printf("Return printf: %%i01	%d\nReturn ft_printf:	%d\n ",printf("Hello: %1i\n", 55), ft_printf("Hello: %1i\n", 55));
	printf("\n\n");
	printf("Return printf: %%i02	%d\nReturn ft_printf:	%d\n ",printf("Hello: %2i\n", 55), ft_printf("Hello: %2i\n", 55));
	printf("\n\n");
	printf("Return printf: %%i03	%d\nReturn ft_printf:	%d\n ",printf("Hello: %3i\n", 55), ft_printf("Hello: %3i\n", 55));
	printf("\n\n");
	printf("Return printf: %%i04	%d\nReturn ft_printf:	%d\n ",printf("Hello: %4i\n", 55), ft_printf("Hello: %4i\n", 55));
	printf("\n\n");
	printf("Return printf: %%i05	%d\nReturn ft_printf:	%d\n ",printf("Hello: %5i\n", 55), ft_printf("Hello: %5i\n", 55));
	printf("\n\n");
	printf("Return printf: %%i06	%d\nReturn ft_printf:	%d\n ",printf("Hello: %6i\n", 55), ft_printf("Hello: %6i\n", 55));
	printf("\n\n");
	printf("Return printf: %%i07	%d\nReturn ft_printf:	%d\n ",printf("Hello: %7i\n", 55), ft_printf("Hello: %7i\n", 55));
	printf("\n\n");
	printf("Return printf: %%i08	%d\nReturn ft_printf:	%d\n ",printf("Hello: %8i\n", 55), ft_printf("Hello: %8i\n", 55));
	printf("\n\n");
	printf("Return printf: %%i09	%d\nReturn ft_printf:	%d\n ",printf("Hello: %9i\n", 55), ft_printf("Hello: %9i\n", 55));
	printf("\n\n");
	printf("Return printf: %%i010	%d\nReturn ft_printf:	%d\n",printf("Hello: %10i\n", 55), ft_printf("Hello: %10i\n", 55));
	printf("\n\n");
	printf("\n\n");
	printf("\n\n");
	printf("\n\n");
}

static void	test_u(void)
{
	int a = 10;
	
	printf("##########################################\n");
	printf("###############   u TEST   ##############\n");
	printf("##########################################\n");	
	printf("---- Test 1 d ----\n");
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Hello %u\n", a), ft_printf("Hello %u\n", a));
	printf("\n\n");
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Hello %u\n", 1), ft_printf("Hello %u\n", 1));
	printf("\n\n");
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Hello %u\n", 0), ft_printf("Hello %u\n", 0));
	printf("\n\n");
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Hello %u\n", -77), ft_printf("Hello %u\n", -77));
	printf("\n\n");
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Hello %u\n", -120000), ft_printf("Hello %u\n", -120000));
	printf("\n\n");
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Hello %u\n", 666666666), ft_printf("Hello %u\n", 666666666));
	printf("\n\n");
	printf("---- Test 1 d with 0 LAG: %%0u ----\n");
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Hello %0u\n", a), ft_printf("Hello %0u\n", a));
	printf("\n\n");
	printf("---- Test 1 d with 0 FLAG: %%00u to %%010u ----\n");
	printf("Return printf: %%u00	%d\nReturn ft_printf:	%d\n ",printf("Hello: %00u\n", 55), ft_printf("Hello: %00u\n", 55));
	printf("\n\n");
	printf("Return printf: %%u01	%d\nReturn ft_printf:	%d\n ",printf("Hello: %01u\n", 55), ft_printf("Hello: %01u\n", 55));
	printf("\n\n");
	printf("Return printf: %%u02	%d\nReturn ft_printf:	%d\n ",printf("Hello: %02u\n", 55), ft_printf("Hello: %02u\n", 55));
	printf("\n\n");
	printf("Return printf: %%u03	%d\nReturn ft_printf:	%d\n ",printf("Hello: %03u\n", 55), ft_printf("Hello: %03u\n", 55));
	printf("\n\n");
	printf("Return printf: %%u04	%d\nReturn ft_printf:	%d\n ",printf("Hello: %04u\n", 55), ft_printf("Hello: %04u\n", 55));
	printf("\n\n");
	printf("Return printf: %%u05	%d\nReturn ft_printf:	%d\n ",printf("Hello: %05u\n", 55), ft_printf("Hello: %05u\n", 55));
	printf("\n\n");
	printf("Return printf: %%u06	%d\nReturn ft_printf:	%d\n ",printf("Hello: %06u\n", 55), ft_printf("Hello: %06u\n", 55));
	printf("\n\n");
	printf("Return printf: %%u07	%d\nReturn ft_printf:	%d\n ",printf("Hello: %07u\n", 55), ft_printf("Hello: %07u\n", 55));
	printf("\n\n");
	printf("Return printf: %%u08	%d\nReturn ft_printf:	%d\n ",printf("Hello: %08u\n", 55), ft_printf("Hello: %08u\n", 55));
	printf("\n\n");
	printf("Return printf: %%u09	%d\nReturn ft_printf:	%d\n ",printf("Hello: %09u\n", 55), ft_printf("Hello: %09u\n", 55));
	printf("\n\n");
	printf("Return printf: %%u010	%d\nReturn ft_printf:	%d\n",printf("Hello: %010u\n", 55), ft_printf("Hello: %010u\n", 55));
	printf("\n\n");
	printf("---- Test 1 d with NO FLAG: %%0u to %%10u ----\n");
	printf("Return printf: %%u00	%d\nReturn ft_printf:	%d\n ",printf("Hello: %0u\n", 55), ft_printf("Hello: %0u\n", 55));
	printf("\n\n");
	printf("Return printf: %%u01	%d\nReturn ft_printf:	%d\n ",printf("Hello: %1u\n", 55), ft_printf("Hello: %1u\n", 55));
	printf("\n\n");
	printf("Return printf: %%u02	%d\nReturn ft_printf:	%d\n ",printf("Hello: %2u\n", 55), ft_printf("Hello: %2u\n", 55));
	printf("\n\n");
	printf("Return printf: %%u03	%d\nReturn ft_printf:	%d\n ",printf("Hello: %3u\n", 55), ft_printf("Hello: %3u\n", 55));
	printf("\n\n");
	printf("Return printf: %%u04	%d\nReturn ft_printf:	%d\n ",printf("Hello: %4u\n", 55), ft_printf("Hello: %4u\n", 55));
	printf("\n\n");
	printf("Return printf: %%u05	%d\nReturn ft_printf:	%d\n ",printf("Hello: %5u\n", 55), ft_printf("Hello: %5u\n", 55));
	printf("\n\n");
	printf("Return printf: %%u06	%d\nReturn ft_printf:	%d\n ",printf("Hello: %6u\n", 55), ft_printf("Hello: %6u\n", 55));
	printf("\n\n");
	printf("Return printf: %%u07	%d\nReturn ft_printf:	%d\n ",printf("Hello: %7u\n", 55), ft_printf("Hello: %7u\n", 55));
	printf("\n\n");
	printf("Return printf: %%u08	%d\nReturn ft_printf:	%d\n ",printf("Hello: %8u\n", 55), ft_printf("Hello: %8u\n", 55));
	printf("\n\n");
	printf("Return printf: %%u09	%d\nReturn ft_printf:	%d\n ",printf("Hello: %9u\n", 55), ft_printf("Hello: %9u\n", 55));
	printf("\n\n");
	printf("Return printf: %%u010	%d\nReturn ft_printf:	%d\n",printf("Hello: %10u\n", 55), ft_printf("Hello: %10u\n", 55));
	printf("\n\n");
	printf("---- Test precision: ----\n");
	printf("Return printf: %%.0s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.0u\n", 55), ft_printf("Hello: %.0u\n", 55));
	printf("Return printf: %%.1s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.1u\n", 55), ft_printf("Hello: %.1u\n", 55));
	printf("Return printf: %%.2s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.2u\n", 55), ft_printf("Hello: %.2u\n", 55));
	printf("Return printf: %%.3s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.3u\n", 55), ft_printf("Hello: %.3u\n", 55));
	printf("Return printf: %%.4s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.4u\n", 55), ft_printf("Hello: %.4u\n", 55));
	printf("Return printf: %%.5s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.5u\n", 55), ft_printf("Hello: %.5u\n", 55));
	printf("Return printf: %%.6s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.6u\n", 55), ft_printf("Hello: %.6u\n", 55));
	printf("Return printf: %%.7s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.7u\n", 55), ft_printf("Hello: %.7u\n", 55));
	printf("Return printf: %%.8s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.8u\n", 55), ft_printf("Hello: %.8u\n", 55));
	printf("Return printf: %%.9s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.9u\n", 55), ft_printf("Hello: %.9u\n", 55));
	printf("Return printf: %%.0s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.0u\n", -55), ft_printf("Hello: %.0u\n", -55));
	printf("Return printf: %%.1s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.1u\n", -55), ft_printf("Hello: %.1u\n", -55));
	printf("Return printf: %%.2s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.2u\n", -55), ft_printf("Hello: %.2u\n", -55));
	printf("Return printf: %%.3s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.3u\n", -55), ft_printf("Hello: %.3u\n", -55));
	printf("Return printf: %%.4s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.4u\n", -55), ft_printf("Hello: %.4u\n", -55));
	printf("Return printf: %%.5s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.5u\n", -55), ft_printf("Hello: %.5u\n", -55));
	printf("Return printf: %%.6s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.6u\n", -55), ft_printf("Hello: %.6u\n", -55));
	printf("Return printf: %%.7s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.7u\n", -55), ft_printf("Hello: %.7u\n", -55));
	printf("Return printf: %%.8s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.8u\n", -55), ft_printf("Hello: %.8u\n", -55));
	printf("Return printf: %%.9s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.9u\n", -55), ft_printf("Hello: %.9u\n", -55));
	printf("\n\n");
	printf("\n\n");
	printf("\n\n");
	printf("\n\n");
}

static void	test_x(void)
{
	int a = 10;

	printf("##########################################\n");
	printf("###############   x TEST   ###############\n");
	printf("##########################################\n");	
	printf("---- Test 1 d ----\n");
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Hello %x\n", a), ft_printf("Hello %x\n", a));
	printf("\n\n");
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Hello %x\n", 1), ft_printf("Hello %x\n", 1));
	printf("\n\n");
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Hello %x\n", 0), ft_printf("Hello %x\n", 0));
	printf("\n\n");
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Hello %x\n", -77), ft_printf("Hello %x\n", -77));
	printf("\n\n");
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Hello %x\n", -120000), ft_printf("Hello %x\n", -120000));
	printf("\n\n");
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Hello %x\n", 666666666), ft_printf("Hello %x\n", 666666666));
	printf("\n\n");
	printf("---- Test 1 d with 0 FLAG: %%0x ----\n");
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Hello %0x\n", a), ft_printf("Hello %0x\n", a));
	printf("\n\n");
	printf("---- Test 1 d with 0 FLAG: %%00x to %%010x ----\n");
	printf("Return printf: %%x00	%d\nReturn ft_printf:	%d\n ",printf("Hello: %00x\n", 55), ft_printf("Hello: %00x\n", 55));
	printf("\n\n");
	printf("Return printf: %%x01	%d\nReturn ft_printf:	%d\n ",printf("Hello: %01x\n", 55), ft_printf("Hello: %01x\n", 55));
	printf("\n\n");
	printf("Return printf: %%x02	%d\nReturn ft_printf:	%d\n ",printf("Hello: %02x\n", 55), ft_printf("Hello: %02x\n", 55));
	printf("\n\n");
	printf("Return printf: %%x03	%d\nReturn ft_printf:	%d\n ",printf("Hello: %03x\n", 55), ft_printf("Hello: %03x\n", 55));
	printf("\n\n");
	printf("Return printf: %%x04	%d\nReturn ft_printf:	%d\n ",printf("Hello: %04x\n", 55), ft_printf("Hello: %04x\n", 55));
	printf("\n\n");
	printf("Return printf: %%x05	%d\nReturn ft_printf:	%d\n ",printf("Hello: %05x\n", 55), ft_printf("Hello: %05x\n", 55));
	printf("\n\n");
	printf("Return printf: %%x06	%d\nReturn ft_printf:	%d\n ",printf("Hello: %06x\n", 55), ft_printf("Hello: %06x\n", 55));
	printf("\n\n");
	printf("Return printf: %%x07	%d\nReturn ft_printf:	%d\n ",printf("Hello: %07x\n", 55), ft_printf("Hello: %07x\n", 55));
	printf("\n\n");
	printf("Return printf: %%x08	%d\nReturn ft_printf:	%d\n ",printf("Hello: %08x\n", 55), ft_printf("Hello: %08x\n", 55));
	printf("\n\n");
	printf("Return printf: %%x09	%d\nReturn ft_printf:	%d\n ",printf("Hello: %09x\n", 55), ft_printf("Hello: %09x\n", 55));
	printf("\n\n");
	printf("Return printf: %%x010	%d\nReturn ft_printf:	%d\n",printf("Hello: %010x\n", 55), ft_printf("Hello: %010x\n", 55));
	printf("\n\n");
	printf("---- Test 1 d with NO FLAG: %%0x to %%10x ----\n");
	printf("Return printf: %%x00	%d\nReturn ft_printf:	%d\n ",printf("Hello: %0x\n", 55), ft_printf("Hello: %0x\n", 55));
	printf("\n\n");
	printf("Return printf: %%x01	%d\nReturn ft_printf:	%d\n ",printf("Hello: %1x\n", 55), ft_printf("Hello: %1x\n", 55));
	printf("\n\n");
	printf("Return printf: %%x02	%d\nReturn ft_printf:	%d\n ",printf("Hello: %2x\n", 55), ft_printf("Hello: %2x\n", 55));
	printf("\n\n");
	printf("Return printf: %%x03	%d\nReturn ft_printf:	%d\n ",printf("Hello: %3x\n", 55), ft_printf("Hello: %3x\n", 55));
	printf("\n\n");
	printf("Return printf: %%x04	%d\nReturn ft_printf:	%d\n ",printf("Hello: %4x\n", 55), ft_printf("Hello: %4x\n", 55));
	printf("\n\n");
	printf("Return printf: %%x05	%d\nReturn ft_printf:	%d\n ",printf("Hello: %5x\n", 55), ft_printf("Hello: %5x\n", 55));
	printf("\n\n");
	printf("Return printf: %%x06	%d\nReturn ft_printf:	%d\n ",printf("Hello: %6x\n", 55), ft_printf("Hello: %6x\n", 55));
	printf("\n\n");
	printf("Return printf: %%x07	%d\nReturn ft_printf:	%d\n ",printf("Hello: %7x\n", 55), ft_printf("Hello: %7x\n", 55));
	printf("\n\n");
	printf("Return printf: %%x08	%d\nReturn ft_printf:	%d\n ",printf("Hello: %8x\n", 55), ft_printf("Hello: %8x\n", 55));
	printf("\n\n");
	printf("Return printf: %%x09	%d\nReturn ft_printf:	%d\n ",printf("Hello: %9x\n", 55), ft_printf("Hello: %9x\n", 55));
	printf("\n\n");
	printf("Return printf: %%x010	%d\nReturn ft_printf:	%d\n",printf("Hello: %010x\n", 55), ft_printf("Hello: %010x\n", 55));
	printf("\n\n");
	printf("---- Test precision: ----\n");
	printf("Return printf: %%.0s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.0x\n", 55), ft_printf("Hello: %.0x\n", 55));
	printf("Return printf: %%.1s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.1x\n", 55), ft_printf("Hello: %.1x\n", 55));
	printf("Return printf: %%.2s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.2x\n", 55), ft_printf("Hello: %.2x\n", 55));
	printf("Return printf: %%.3s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.3x\n", 55), ft_printf("Hello: %.3x\n", 55));
	printf("Return printf: %%.4s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.4x\n", 55), ft_printf("Hello: %.4x\n", 55));
	printf("Return printf: %%.5s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.5x\n", 55), ft_printf("Hello: %.5x\n", 55));
	printf("Return printf: %%.6s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.6x\n", 55), ft_printf("Hello: %.6x\n", 55));
	printf("Return printf: %%.7s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.7x\n", 55), ft_printf("Hello: %.7x\n", 55));
	printf("Return printf: %%.8s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.8x\n", 55), ft_printf("Hello: %.8x\n", 55));
	printf("Return printf: %%.9s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.9x\n", 55), ft_printf("Hello: %.9x\n", 55));
	printf("Return printf: %%.0s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.0x\n", -55), ft_printf("Hello: %.0x\n", -55));
	printf("Return printf: %%.1s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.1x\n", -55), ft_printf("Hello: %.1x\n", -55));
	printf("Return printf: %%.2s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.2x\n", -55), ft_printf("Hello: %.2x\n", -55));
	printf("Return printf: %%.3s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.3x\n", -55), ft_printf("Hello: %.3x\n", -55));
	printf("Return printf: %%.4s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.4x\n", -55), ft_printf("Hello: %.4x\n", -55));
	printf("Return printf: %%.5s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.5x\n", -55), ft_printf("Hello: %.5x\n", -55));
	printf("Return printf: %%.6s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.6x\n", -55), ft_printf("Hello: %.6x\n", -55));
	printf("Return printf: %%.7s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.7x\n", -55), ft_printf("Hello: %.7x\n", -55));
	printf("Return printf: %%.8s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.8x\n", -55), ft_printf("Hello: %.8x\n", -55));
	printf("Return printf: %%.9s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.9x\n", -55), ft_printf("Hello: %.9x\n", -55));
	printf("\n\n");
	printf("\n\n");
	printf("\n\n");
	printf("\n\n");
}

static void	test_X(void)
{
	int a = 10;

	printf("##########################################\n");
	printf("###############   X TEST   ###############\n");
	printf("##########################################\n");	
	printf("---- Test 1 d ----\n");
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Hello %X\n", a), ft_printf("Hello %X\n", a));
	printf("\n\n");
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Hello %X\n", 1), ft_printf("Hello %X\n", 1));
	printf("\n\n");
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Hello %X\n", 0), ft_printf("Hello %X\n", 0));
	printf("\n\n");
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Hello %X\n", -77), ft_printf("Hello %X\n", -77));
	printf("\n\n");
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Hello %X\n", -120000), ft_printf("Hello %X\n", -120000));
	printf("\n\n");
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Hello %X\n", 666666666), ft_printf("Hello %X\n", 666666666));
	printf("\n\n");
	printf("---- Test 1 d with 0 FLAG: %%0X ----\n");
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Hello %0X\n", a), ft_printf("Hello %0X\n", a));
	printf("\n\n");
	printf("---- Test 1 d with 0 FLAG: %%00X to %%10X ----\n");
	printf("Return printf: %%X00	%d\nReturn ft_printf:	%d\n ",printf("Hello: %00X\n", 55), ft_printf("Hello: %00X\n", 55));
	printf("\n\n");
	printf("Return printf: %%X01	%d\nReturn ft_printf:	%d\n ",printf("Hello: %01X\n", 55), ft_printf("Hello: %01X\n", 55));
	printf("\n\n");
	printf("Return printf: %%X02	%d\nReturn ft_printf:	%d\n ",printf("Hello: %02X\n", 55), ft_printf("Hello: %02X\n", 55));
	printf("\n\n");
	printf("Return printf: %%X03	%d\nReturn ft_printf:	%d\n ",printf("Hello: %03X\n", 55), ft_printf("Hello: %03X\n", 55));
	printf("\n\n");
	printf("Return printf: %%X04	%d\nReturn ft_printf:	%d\n ",printf("Hello: %04X\n", 55), ft_printf("Hello: %04X\n", 55));
	printf("\n\n");
	printf("Return printf: %%X05	%d\nReturn ft_printf:	%d\n ",printf("Hello: %05X\n", 55), ft_printf("Hello: %05X\n", 55));
	printf("\n\n");
	printf("Return printf: %%X06	%d\nReturn ft_printf:	%d\n ",printf("Hello: %06X\n", 55), ft_printf("Hello: %06X\n", 55));
	printf("\n\n");
	printf("Return printf: %%X07	%d\nReturn ft_printf:	%d\n ",printf("Hello: %07X\n", 55), ft_printf("Hello: %07X\n", 55));
	printf("\n\n");
	printf("Return printf: %%X08	%d\nReturn ft_printf:	%d\n ",printf("Hello: %08X\n", 55), ft_printf("Hello: %08X\n", 55));
	printf("\n\n");
	printf("Return printf: %%X09	%d\nReturn ft_printf:	%d\n ",printf("Hello: %09X\n", 55), ft_printf("Hello: %09X\n", 55));
	printf("\n\n");
	printf("Return printf: %%X010	%d\nReturn ft_printf:	%d\n",printf("Hello: %010X\n", 55), ft_printf("Hello: %010X\n", 55));
	printf("\n\n");
	printf("---- Test 1 d with NO FLAG: %%0X to %%10X ----\n");
	printf("Return printf: %%X00	%d\nReturn ft_printf:	%d\n ",printf("Hello: %0X\n", 55), ft_printf("Hello: %0X\n", 55));
	printf("\n\n");
	printf("Return printf: %%X01	%d\nReturn ft_printf:	%d\n ",printf("Hello: %1X\n", 55), ft_printf("Hello: %1X\n", 55));
	printf("\n\n");
	printf("Return printf: %%X02	%d\nReturn ft_printf:	%d\n ",printf("Hello: %2X\n", 55), ft_printf("Hello: %2X\n", 55));
	printf("\n\n");
	printf("Return printf: %%X03	%d\nReturn ft_printf:	%d\n ",printf("Hello: %3X\n", 55), ft_printf("Hello: %3X\n", 55));
	printf("\n\n");
	printf("Return printf: %%X04	%d\nReturn ft_printf:	%d\n ",printf("Hello: %4X\n", 55), ft_printf("Hello: %4X\n", 55));
	printf("\n\n");
	printf("Return printf: %%X05	%d\nReturn ft_printf:	%d\n ",printf("Hello: %5X\n", 55), ft_printf("Hello: %5X\n", 55));
	printf("\n\n");
	printf("Return printf: %%X06	%d\nReturn ft_printf:	%d\n ",printf("Hello: %6X\n", 55), ft_printf("Hello: %6X\n", 55));
	printf("\n\n");
	printf("Return printf: %%X07	%d\nReturn ft_printf:	%d\n ",printf("Hello: %7X\n", 55), ft_printf("Hello: %7X\n", 55));
	printf("\n\n");
	printf("Return printf: %%X08	%d\nReturn ft_printf:	%d\n ",printf("Hello: %8X\n", 55), ft_printf("Hello: %8X\n", 55));
	printf("\n\n");
	printf("Return printf: %%X09	%d\nReturn ft_printf:	%d\n ",printf("Hello: %9X\n", 55), ft_printf("Hello: %9X\n", 55));
	printf("\n\n");
	printf("Return printf: %%X010	%d\nReturn ft_printf:	%d\n",printf("Hello: %10X\n", 55), ft_printf("Hello: %10X\n", 55));
	printf("\n\n");
	printf("---- Test precision: ----\n");
	printf("Return printf: %%.0s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.0X\n", 55), ft_printf("Hello: %.0X\n", 55));
	printf("Return printf: %%.1s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.1X\n", 55), ft_printf("Hello: %.1X\n", 55));
	printf("Return printf: %%.2s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.2X\n", 55), ft_printf("Hello: %.2X\n", 55));
	printf("Return printf: %%.3s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.3X\n", 55), ft_printf("Hello: %.3X\n", 55));
	printf("Return printf: %%.4s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.4X\n", 55), ft_printf("Hello: %.4X\n", 55));
	printf("Return printf: %%.5s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.5X\n", 55), ft_printf("Hello: %.5X\n", 55));
	printf("Return printf: %%.6s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.6X\n", 55), ft_printf("Hello: %.6X\n", 55));
	printf("Return printf: %%.7s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.7X\n", 55), ft_printf("Hello: %.7X\n", 55));
	printf("Return printf: %%.8s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.8X\n", 55), ft_printf("Hello: %.8X\n", 55));
	printf("Return printf: %%.9s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.9X\n", 55), ft_printf("Hello: %.9X\n", 55));
	printf("Return printf: %%.0s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.0X\n", -55), ft_printf("Hello: %.0X\n", -55));
	printf("Return printf: %%.1s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.1X\n", -55), ft_printf("Hello: %.1X\n", -55));
	printf("Return printf: %%.2s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.2X\n", -55), ft_printf("Hello: %.2X\n", -55));
	printf("Return printf: %%.3s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.3X\n", -55), ft_printf("Hello: %.3X\n", -55));
	printf("Return printf: %%.4s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.4X\n", -55), ft_printf("Hello: %.4X\n", -55));
	printf("Return printf: %%.5s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.5X\n", -55), ft_printf("Hello: %.5X\n", -55));
	printf("Return printf: %%.6s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.6X\n", -55), ft_printf("Hello: %.6X\n", -55));
	printf("Return printf: %%.7s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.7X\n", -55), ft_printf("Hello: %.7X\n", -55));
	printf("Return printf: %%.8s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.8X\n", -55), ft_printf("Hello: %.8X\n", -55));
	printf("Return printf: %%.9s	%d\nReturn ft_printf:	%d\n",printf("Hello: %.9X\n", -55), ft_printf("Hello: %.9X\n", -55));
	printf("\n\n");
	printf("\n\n");
	printf("\n\n");
	printf("\n\n");

}

static void	test_p(void)
{
	int a = 10;
	int *b = &a;

	printf("##########################################\n");
	printf("###############   p TEST   ###############\n");
	printf("##########################################\n");	
/* 	printf("---- Test 1 p ----\n");  // UNDEFINED BEHAVIOUR
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Hello %p\n", b), ft_printf("Hello %p\n", b));
	printf("\n\n");
	printf("---- Test 1 d with 0 FLAG: %%0p ----\n");  // UNDEFINED BEHAVIOUR
	printf("Return printf:		%s\nReturn ft_printf:	%s\n", printf("Hello %0p\n", b), ft_printf("Hello %0p\n", b));
	printf("\n\n");
	printf("---- Test 1 d with 0 FLAG: %%00p to %%010p ----\n");  // UNDEFINED BEHAVIOUR
	printf("Return printf: %%p00	%d\nReturn ft_printf:	%d\n ",printf("Hello: %00p\n", b), ft_printf("Hello: %00p\n", b));
	printf("\n\n");
	printf("Return printf: %%p01	%d\nReturn ft_printf:	%d\n ",printf("Hello: %01p\n", b), ft_printf("Hello: %01p\n", b));
	printf("\n\n");
	printf("Return printf: %%p02	%d\nReturn ft_printf:	%d\n ",printf("Hello: %02p\n", b), ft_printf("Hello: %02p\n", b));
	printf("\n\n");
	printf("Return printf: %%p03	%d\nReturn ft_printf:	%d\n ",printf("Hello: %03p\n", b), ft_printf("Hello: %03p\n", b));
	printf("\n\n");
	printf("Return printf: %%p04	%d\nReturn ft_printf:	%d\n ",printf("Hello: %04p\n", b), ft_printf("Hello: %04p\n", b));
	printf("\n\n");
	printf("Return printf: %%p05	%d\nReturn ft_printf:	%d\n ",printf("Hello: %05p\n", b), ft_printf("Hello: %05p\n", b));
	printf("\n\n");
	printf("Return printf: %%p06	%d\nReturn ft_printf:	%d\n ",printf("Hello: %06p\n", b), ft_printf("Hello: %06p\n", b));
	printf("\n\n");
	printf("Return printf: %%p07	%d\nReturn ft_printf:	%d\n ",printf("Hello: %07p\n", b), ft_printf("Hello: %07p\n", b));
	printf("\n\n");
	printf("Return printf: %%p08	%d\nReturn ft_printf:	%d\n ",printf("Hello: %08p\n", b), ft_printf("Hello: %08p\n", b));
	printf("\n\n");
	printf("Return printf: %%p09	%d\nReturn ft_printf:	%d\n ",printf("Hello: %09p\n", b), ft_printf("Hello: %09p\n", b));
	printf("\n\n");
	printf("Return printf: %%p010	%d\nReturn ft_printf:	%d\n",printf("Hello: %010p\n", b), ft_printf("Hello: %010p\n", b));
	printf("\n\n"); 
	printf("---- Test 1 d with NO FLAG: %%0p to %%10p ----\n");  // UNDEFINED BEHAVIOUR
	printf("Return printf: %%p00	%d\nReturn ft_printf:	%d\n ",printf("Hello: %0p\n", b), ft_printf("Hello: %0p\n", b));
	printf("\n\n"); 
	printf("Return printf: %%p0	%d\nReturn ft_printf:	%d\n ",printf("Hello: %0p\n", b), ft_printf("Hello: %0p\n", b));
	printf("\n\n");*/
	printf("Return printf: %%p01	%d\nReturn ft_printf:	%d\n ",printf("Hello: %1p\n", b), ft_printf("Hello: %1p\n", b));
	printf("\n\n");
	printf("Return printf: %%p02	%d\nReturn ft_printf:	%d\n ",printf("Hello: %2p\n", b), ft_printf("Hello: %2p\n", b));
	printf("\n\n");
	printf("Return printf: %%p03	%d\nReturn ft_printf:	%d\n ",printf("Hello: %3p\n", b), ft_printf("Hello: %3p\n", b));
	printf("\n\n");
	printf("Return printf: %%p04	%d\nReturn ft_printf:	%d\n ",printf("Hello: %4p\n", b), ft_printf("Hello: %4p\n", b));
	printf("\n\n");
	printf("Return printf: %%p05	%d\nReturn ft_printf:	%d\n ",printf("Hello: %5p\n", b), ft_printf("Hello: %5p\n", b));
	printf("\n\n");
	printf("Return printf: %%p06	%d\nReturn ft_printf:	%d\n ",printf("Hello: %6p\n", b), ft_printf("Hello: %6p\n", b));
	printf("\n\n");
	printf("Return printf: %%p07	%d\nReturn ft_printf:	%d\n ",printf("Hello: %7p\n", b), ft_printf("Hello: %7p\n", b));
	printf("\n\n");
	printf("Return printf: %%p08	%d\nReturn ft_printf:	%d\n ",printf("Hello: %8p\n", b), ft_printf("Hello: %8p\n", b));
	printf("\n\n");
	printf("Return printf: %%p09	%d\nReturn ft_printf:	%d\n ",printf("Hello: %9p\n", b), ft_printf("Hello: %9p\n", b));
	printf("\n\n");
	printf("Return printf: %%p010	%d\nReturn ft_printf:	%d\n",printf("Hello: %10p\n", b), ft_printf("Hello: %10p\n", b));
	printf("\n\n");
	printf("Return printf: %%p11	%d\nReturn ft_printf:	%d\n ",printf("Hello: %11p\n", b), ft_printf("Hello: %11p\n", b));
	printf("\n\n");
	printf("Return printf: %%p12	%d\nReturn ft_printf:	%d\n ",printf("Hello: %12p\n", b), ft_printf("Hello: %12p\n", b));
	printf("\n\n");
	printf("Return printf: %%p13	%d\nReturn ft_printf:	%d\n ",printf("Hello: %13p\n", b), ft_printf("Hello: %13p\n", b));
	printf("\n\n");
	printf("Return printf: %%p14	%d\nReturn ft_printf:	%d\n ",printf("Hello: %14p\n", b), ft_printf("Hello: %14p\n", b));
	printf("\n\n");
	printf("Return printf: %%p15	%d\nReturn ft_printf:	%d\n ",printf("Hello: %15p\n", b), ft_printf("Hello: %15p\n", b));
	printf("\n\n");
	printf("Return printf: %%p16	%d\nReturn ft_printf:	%d\n ",printf("Hello: %16p\n", b), ft_printf("Hello: %16p\n", b));
	printf("\n\n");
	printf("Return printf: %%p17	%d\nReturn ft_printf:	%d\n ",printf("Hello: %17p\n", b), ft_printf("Hello: %17p\n", b));
	printf("\n\n");
	printf("Return printf: %%p18	%d\nReturn ft_printf:	%d\n ",printf("Hello: %18p\n", b), ft_printf("Hello: %18p\n", b));
	printf("\n\n");
	printf("Return printf: %%p19	%d\nReturn ft_printf:	%d\n ",printf("Hello: %19p\n", b), ft_printf("Hello: %19p\n", b));
	printf("\n\n");
	printf("Return printf: %%p20	%d\nReturn ft_printf:	%d\n",printf("Hello: %20p\n", b), ft_printf("Hello: %20p\n", b));
	printf("\n\n");
/* 	printf("Return printf: %%p.0	%d\nReturn ft_printf:	%d\n ",printf("Hello: %.0p\n", b), ft_printf("Hello: %.0p\n", b));
	printf("\n\n");
	printf("Return printf: %%p.01	%d\nReturn ft_printf:	%d\n ",printf("Hello: %.1p\n", b), ft_printf("Hello: %.1p\n", b));
	printf("\n\n");
	printf("Return printf: %%p.02	%d\nReturn ft_printf:	%d\n ",printf("Hello: %.2p\n", b), ft_printf("Hello: %.2p\n", b));
	printf("\n\n");
	printf("Return printf: %%p.03	%d\nReturn ft_printf:	%d\n ",printf("Hello: %.3p\n", b), ft_printf("Hello: %.3p\n", b));
	printf("\n\n");
	printf("Return printf: %%p.04	%d\nReturn ft_printf:	%d\n ",printf("Hello: %.4p\n", b), ft_printf("Hello: %.4p\n", b));
	printf("\n\n");
	printf("Return printf: %%p.05	%d\nReturn ft_printf:	%d\n ",printf("Hello: %.5p\n", b), ft_printf("Hello: %.5p\n", b));
	printf("\n\n");
	printf("Return printf: %%p.06	%d\nReturn ft_printf:	%d\n ",printf("Hello: %.6p\n", b), ft_printf("Hello: %.6p\n", b));
	printf("\n\n");
	printf("Return printf: %%p.07	%d\nReturn ft_printf:	%d\n ",printf("Hello: %.7p\n", b), ft_printf("Hello: %.7p\n", b));
	printf("\n\n");
	printf("Return printf: %%p.08	%d\nReturn ft_printf:	%d\n ",printf("Hello: %.8p\n", b), ft_printf("Hello: %.8p\n", b));
	printf("\n\n");
	printf("Return printf: %%p.09	%d\nReturn ft_printf:	%d\n ",printf("Hello: %.9p\n", b), ft_printf("Hello: %.9p\n", b));
	printf("\n\n");
	printf("Return printf: %%p.010	%d\nReturn ft_printf:	%d\n",printf("Hello: %.10p\n", b), ft_printf("Hello: %.10p\n", b));
	printf("\n\n");
	printf("Return printf: %%p.11	%d\nReturn ft_printf:	%d\n ",printf("Hello: %.11p\n", b), ft_printf("Hello: %.11p\n", b));
	printf("\n\n");
	printf("Return printf: %%p.12	%d\nReturn ft_printf:	%d\n ",printf("Hello: %.12p\n", b), ft_printf("Hello: %.12p\n", b));
	printf("\n\n");
	printf("Return printf: %%p.13	%d\nReturn ft_printf:	%d\n ",printf("Hello: %.13p\n", b), ft_printf("Hello: %.13p\n", b));
	printf("\n\n");
	printf("Return printf: %%p.14	%d\nReturn ft_printf:	%d\n ",printf("Hello: %.14p\n", b), ft_printf("Hello: %.14p\n", b));
	printf("\n\n");
	printf("Return printf: %%p.15	%d\nReturn ft_printf:	%d\n ",printf("Hello: %.15p\n", b), ft_printf("Hello: %.15p\n", b));
	printf("\n\n");
	printf("Return printf: %%p.16	%d\nReturn ft_printf:	%d\n ",printf("Hello: %.16p\n", b), ft_printf("Hello: %.16p\n", b));
	printf("\n\n");
	printf("Return printf: %%p.17	%d\nReturn ft_printf:	%d\n ",printf("Hello: %.17p\n", b), ft_printf("Hello: %.17p\n", b));
	printf("\n\n");
	printf("Return printf: %%p.18	%d\nReturn ft_printf:	%d\n ",printf("Hello: %.18p\n", b), ft_printf("Hello: %.18p\n", b));
	printf("\n\n");
	printf("Return printf: %%p.19	%d\nReturn ft_printf:	%d\n ",printf("Hello: %.19p\n", b), ft_printf("Hello: %.19p\n", b));
	printf("\n\n");
	printf("Return printf: %%p.20	%d\nReturn ft_printf:	%d\n",printf("Hello: %.20p\n", b), ft_printf("Hello: %.20p\n", b)); */
	printf("\n\n");
	printf("\n\n");
	printf("\n\n");
	printf("\n\n");
}

static void	test_perc(void)
{
	printf("##########################################\n");
	printf("############   PERCENT TEST   ###########\n");
	printf("##########################################\n");	
	printf("---- Test 1: %% ----\n");
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Hello %%\n"), ft_printf("Hello %%\n"));
	printf("\n\n");
	printf("---- Test Multi %% ----\n");
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Hello %%%%%%%%%%\n"), ft_printf("Hello %%%%%%%%%%\n"));
	printf("\n\n");
/* 	printf("---- Test 1 d with FLAG: %%0%% ----\n");
	printf("Return printf:		%s\nReturn ft_printf:	%s\n", printf("Hello %0%\n", '%'), ft_printf("Hello %0%\n", '%'));
	printf("\n\n");
	printf("---- Test 1 d with FLAG: %%00%%  to %%010%%  ----\n");
	printf("Return printf: %%%%00	%d\nReturn ft_printf:	%d\n ",printf("Hello: %00%\n"), ft_printf("Hello: %00%\n"));
	printf("\n\n");
	printf("Return printf: %%%%01	%d\nReturn ft_printf:	%d\n ",printf("Hello: %01%\n"), ft_printf("Hello: %01%\n"));
	printf("\n\n");
	printf("Return printf: %%%%02	%d\nReturn ft_printf:	%d\n ",printf("Hello: %02%\n"), ft_printf("Hello: %02%\n"));
	printf("\n\n"); */
	printf("---- Test 1 d with FLAG: %%0%%  to %%10%%  ----\n");
	printf("Return printf: %%%%0	%d\nReturn ft_printf:	%d\n ",printf("Hello: %0%\n"), ft_printf("Hello: %0%\n"));
	printf("\n\n");
	printf("Return printf: %%%%1	%d\nReturn ft_printf:	%d\n ",printf("Hello: %1%\n"), ft_printf("Hello: %1%\n"));
	printf("\n\n");
	printf("Return printf: %%%%2	%d\nReturn ft_printf:	%d\n ",printf("Hello: %2%\n"), ft_printf("Hello: %2%\n"));
	printf("\n\n");
	printf("\n\n");
	printf("\n\n");
	printf("\n\n");
}

static void		easy(void)
{
	printf("\n\n\nHello: %4.2s\n\n\n\n", "Hi!");
	ft_printf("\n\n\nHello: %4.2s\n\n\n\n", "Hi!");
}


static void 	all_tests(void)
{
	test_s();
	test_c();
	test_d();
	test_i();
	test_u();
	test_x();
	test_X();
	test_p();
	test_perc();
}

int		main(int argc, char **argv)
{	
	(void) argc;

	if (strcmp(argv[1],"all") == 0 || strcmp(argv[1],"") == 0)
		all_tests();
	else if (strcmp(argv[1],"s") == 0)
		test_s();
	else if (strcmp(argv[1],"c") == 0)
		test_c();
	else if (strcmp(argv[1],"d") == 0)
		test_d();
	else if (strcmp(argv[1],"i") == 0)
		test_i();
	else if (strcmp(argv[1],"u") == 0)
		test_u();
	else if (strcmp(argv[1],"x") == 0)
		test_x();
	else if (strcmp(argv[1],"X") == 0)
		test_X();
	else if (strcmp(argv[1],"p") == 0)
		test_p();
	else if (strcmp(argv[1],"perce") == 0)
		test_perc();
	else if (strcmp(argv[1],"easy") == 0)
		easy();
	return (0);
}