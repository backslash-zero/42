/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:19:18 by cmeunier          #+#    #+#             */
/*   Updated: 2019/10/22 16:09:51 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*s;
	char	*d;
	size_t	i;

	if (!dst && !src)
		return (0);
	s = (char *)src;
	d = (char *)dst;
	i = 0;
	if (dst < src)
		while (n-- > 0)
			*d++ = *s++;
	else
		while (n-- > 0)
			d[n] = s[n];
	return (dst);
}
