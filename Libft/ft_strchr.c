/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:22:15 by cmeunier          #+#    #+#             */
/*   Updated: 2019/10/10 16:04:01 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *)s;
	if (c == '\0')
		return (&ptr[ft_strlen(s)]);
	while (*ptr != c && *ptr)
		ptr++;
	if (!*ptr)
		return (NULL);
	return (ptr);
}
