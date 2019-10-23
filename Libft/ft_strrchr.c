/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 10:28:36 by cmeunier          #+#    #+#             */
/*   Updated: 2019/10/21 19:11:37 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	char	*start;

	ptr = (char *)s;
	start = (char *)s;
	if (c == '\0')
		return (&ptr[ft_strlen(s)]);
	while (*ptr)
		ptr++;
	while (*ptr != c && ptr != start)
		ptr--;
	if (ptr == start && *ptr != c)
		return (NULL);
	return (ptr);
}
