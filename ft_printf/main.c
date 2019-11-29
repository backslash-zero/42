/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 11:37:06 by cmeunier          #+#    #+#             */
/*   Updated: 2019/11/29 17:42:33 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <string.h>

int		main(void)
{
	int a = 10;
	int *b = &a;
	
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
	printf("\n\n");
	printf("\n\n");
	printf("\n\n");

	printf("##########################################\n");
	printf("###############   c TEST   ###############\n");
	printf("##########################################\n");
	printf("---- Test 1 /%% with 1c && no flags ----\n");
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Hello %c\n", 'C'), ft_printf("Hello %c\n", 'C'));
	printf("\n\n");
	printf("---- Test 1 /%% with 5c && no flags ----\n");
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Hello %c%c%c%c%c\n", 'C', 'C', 'C', 'C', 'C'), ft_printf("Hello %c%c%c%c%c\n", 'C', 'C', 'C', 'C', 'C'));
	printf("\n\n");
	printf("\n\n");
	printf("\n\n");
	printf("\n\n");

	printf("##########################################\n");
	printf("############   PERCENT TEST   ###########\n");
	printf("##########################################\n");	
	printf("---- Test 1 %% ----\n");
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Hello %%\n"), ft_printf("Hello %%\n"));
	printf("\n\n");
	printf("---- Test Multi %% ----\n");
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Hello %%%%%%%%%%\n"), ft_printf("Hello %%%%%%%%%%\n"));
	printf("\n\n");
	printf("\n\n");
	printf("\n\n");
	printf("\n\n");

	printf("##########################################\n");
	printf("###############   p TEST   ###############\n");
	printf("##########################################\n");	
	printf("---- Test 1 p ----\n");
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Hello %p\n", b), ft_printf("Hello %p\n", b));
	printf("\n\n");
	printf("\n\n");
	printf("\n\n");
	printf("\n\n");


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
	printf("---- Test 1 d with FLAG: %%0d ----\n");
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Hello %0d\n", a), ft_printf("Hello %0d\n", a));
	printf("\n\n");
	printf("---- Test 1 d with FLAG: %%00d to %%010d ----\n");
	printf("Return: %d\n",printf("Hello: %00d\n", 55));
	printf("Return: %d\n",printf("Hello: %01d\n", 55));
	printf("Return: %d\n",printf("Hello: %02d\n", 55));
	printf("Return: %d\n",printf("Hello: %03d\n", 55));
	printf("Return: %d\n",printf("Hello: %04d\n", 55));
	printf("Return: %d\n",printf("Hello: %05d\n", 55));
	printf("Return: %d\n",printf("Hello: %06d\n", 55));
	printf("Return: %d\n",printf("Hello: %07d\n", 55));
	printf("Return: %d\n",printf("Hello: %08d\n", 55));
	printf("Return: %d\n",printf("Hello: %09d\n", 55));
	printf("Return: %d\n",printf("Hello: %010d\n", 55));
	printf("Return: %d\n",printf("Hello: %05d\n", 55));
	printf("Return: %d\n",printf("Hello: %06d\n", 55));
	printf("\n\n");
	printf("\n\n");
	printf("\n\n");
	printf("\n\n");

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
	printf("---- Test 1 d with FLAG: %%0i ----\n");
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Hello %0i\n", a), ft_printf("Hello %0i\n", a));
	printf("\n\n");
	printf("\n\n");
	printf("\n\n");
	printf("\n\n");


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
	printf("---- Test 1 d with FLAG: %%0u ----\n");
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Hello %0u\n", a), ft_printf("Hello %0u\n", a));
	printf("\n\n");
	printf("\n\n");
	printf("\n\n");
	printf("\n\n");

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
	printf("---- Test 1 d with FLAG: %%0x ----\n");
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Hello %0x\n", a), ft_printf("Hello %0x\n", a));
	printf("\n\n");
	printf("\n\n");
	printf("\n\n");
	printf("\n\n");

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
	printf("---- Test 1 d with FLAG: %%0X ----\n");
	printf("Return printf:		%d\nReturn ft_printf:	%d\n", printf("Hello %0X\n", a), ft_printf("Hello %0X\n", a));
	printf("\n\n");
	printf("\n\n");
	printf("\n\n");
	printf("\n\n");

	return (0);
}
