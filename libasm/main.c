/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 10:55:29 by cmeunier          #+#    #+#             */
/*   Updated: 2020/05/04 17:49:56 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

// prototypes
int		ft_strlen(char const *str);
char	*ft_strcpy(char * dst, const char * src);

// main
int     main(void)
{
    char *a = "bonjour les petits enfants";
    char *b = "";
    //char *c = NULL;
    char *d = "hey";

	// strlen (strlen segfaults with NULL pointer)
    printf("strlen:		%lu\nft_strlen:	%d\n__\n",strlen(a), ft_strlen(a));
    printf("strlen:		%lu\nft_strlen:	%d\n__\n",strlen(b), ft_strlen(b));
	printf("strlen:		%lu\nft_strlen:	%d\n__\n",strlen(d), ft_strlen(d));

	// strcpy
	char new_a[strlen(a)];
	char ft_new_a[strlen(a)];
	printf("strcpy:		%s\n",strcpy(new_a, a));
	printf("strcpy:		%s\nft_strcpy:	%s\n__\n",strcpy(new_a, a), ft_strcpy(ft_new_a, a));
	//printf("strcpy:		%s\nft_strcpy:	%s\n__\n",strcpy(new, b), ft_strcpy(new, b));
	//printf("strcpy:		%s\nft_strcpy:	%s\n__\n",strcpy(new, c), ft_strcpy(new, c));
	//printf("strcpy:		%s\nft_strcpy:	%s\n__\n",strcpy(new, d), ft_strcpy(new, d));
}
