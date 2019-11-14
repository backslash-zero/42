/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:04:44 by cmeunier          #+#    #+#             */
/*   Updated: 2019/11/01 17:33:38 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

void    ft_bzero(void *s, size_t n)
{
        ft_memset(s, 0, n);
}

size_t  ft_strlen(const char *s)
{
        int l;

        l = 0;
        if(!s)
                return (0);
        while (s[l])
                l++;
        return (l);
}

void    *ft_memset(void *b, int c, size_t len)
{
        unsigned char *ptr;

        ptr = b;
        while (len-- > 0)
                *ptr++ = (unsigned char)c;
        return (b);
}

void    *ft_calloc(size_t count, size_t size)
{
        void *ptr;

        if (!(ptr = malloc(count * size)))
                return (0);
        ft_bzero(ptr, count * size);
        return (ptr);
}

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
        char    *str;
        int     i;

        i = 0;
        if (!s)
                return (NULL);
        if (start >= (unsigned int)ft_strlen(s))
                return (ft_calloc(1, 1));
        if (!(str = malloc(sizeof(char) * (len + 1))))
                return (NULL);
        while (len-- > 0)
                str[i++] = s[start++];
        str[i] = '\0';
        return (str);
}
