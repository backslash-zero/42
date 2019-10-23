/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:22:56 by cmeunier          #+#    #+#             */
/*   Updated: 2019/10/22 17:06:50 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *nd, size_t len)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	j = 0;
	ptr = 0;
	if (!nd[0])
		return (char*)h;
	while (h[i] && nd[j] && len-- > 0)
	{
		if (h[i] == nd[j])
		{
			if (j == 0)
				ptr = (char*)(h + i);
			j++;
		}
		else
			j = 0;
		i++;
	}
	if (!nd[j])
		return (ptr);
	return (NULL);
}
