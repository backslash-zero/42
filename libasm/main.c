/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 10:55:29 by cmeunier          #+#    #+#             */
/*   Updated: 2020/05/04 12:12:22 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int     main(void)
{
    char *a = "bonjour les petits enfants";
    char *b = "";
    char *c = NULL;
    char *d = "hey";

    printf("strlen:     %d\nft_strlen:      %d",strlen(a), ft_strlen(a));
}