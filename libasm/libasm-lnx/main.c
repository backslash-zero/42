/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 10:55:29 by cmeunier          #+#    #+#             */
/*   Updated: 2020/05/07 19:16:46 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

// prototypes
int		ft_strlen(char const *str);
char	*ft_strcpy(char * dst, const char * src);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *s1);




// main
int     main(void)
{
    char *a = "bonjour les petits enfants";
    char *b = "";
    // char *c = NULL;
    char *d = "hey";

	// strlen (strlen segfaults with NULL pointer)
    printf("strlen:		%lu\nft_strlen:	%d\n__\n",strlen(a), ft_strlen(a));
    printf("strlen:		%lu\nft_strlen:	%d\n__\n",strlen(b), ft_strlen(b));
	printf("strlen:		%lu\nft_strlen:	%d\n__\n",strlen(d), ft_strlen(d));

	// strcpy
	char new_a[strlen(a)];
	char ft_new_a[strlen(a)];
	char new_b[strlen(b)];
	char ft_new_b[strlen(b)];
	char new_d[strlen(d)];
	char ft_new_d[strlen(d)];
	printf("strcpy:		%s\n",strcpy(new_a, a));
	printf("strcpy:		%s\nft_strcpy:	%s\n__\n",strcpy(new_a, a), ft_strcpy(ft_new_a, a));
	printf("strcpy:		%s\nft_strcpy:	%s\n__\n",strcpy(new_b, b), ft_strcpy(ft_new_b, b));
	printf("strcpy:		%s\nft_strcpy:	%s\n__\n",strcpy(new_d, d), ft_strcpy(ft_new_d, d));

	//strcmp
	printf("strcmp:		%d\nft_strcmp:	%d\n__\n",strcmp("hey",""),ft_strcmp("hey",""));
	printf("strcmp:		%d\nft_strcmp:	%d\n__\n",strcmp("célestin  le peetit coquin","célestin  le petit coquin"),ft_strcmp("célestin  le peetit coquin","célestin  le petit coquin"));
	printf("strcmp:		%d\nft_strcmp:	%d\n__\n",strcmp("célestin  le petit coquin","célestin  le petit coquin"),ft_strcmp("célestin  le petit coquin","célestin  le petit coquin"));
	printf("strcmp:		%d\nft_strcmp:	%d\n__\n",strcmp("ho","ho"),ft_strcmp("ho","ho"));
	printf("strcmp:		%d\nft_strcmp:	%d\n__\n",strcmp("",""),ft_strcmp("",""));
	printf("strcmp:		%d\nft_strcmp:	%d\n__\n",strcmp("hey","ho"),ft_strcmp("hey","ho"));
	printf("strcmp:		%d\nft_strcmp:	%d\n__\n",strcmp("célestin  le ptit coquin","célestin  le petit coquin"),ft_strcmp("célestin  le ptit coquin","célestin  le petit coquin"));
	printf("strcmp:		%d\nft_strcmp:	%d\n__\n",ft_strcmp(NULL, NULL),ft_strcmp(NULL, NULL));

	//strdup
	printf("strdup:		%s\nft_strdup:	%s\n__\n", strdup(a), ft_strdup(a));
	printf("strdup:		%s\nft_strdup:	%s\n__\n", strdup(b), ft_strdup(b));
	//printf("strdup:		%s\n__\nft_strdup:	%s\n", strdup(a), ft_strdup(a));
	printf("strdup:		%s\nft_strdup:	%s\n__\n", strdup(d), ft_strdup(d));
	
	
	char buffer[100];
	int i = 0;
	while(1 < 100)
		buffer[i++] = 0;
	int fd = open("Makefile");
	
	read(fd, )
}
