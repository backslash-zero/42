/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_susbtr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 16:45:22 by cmeunier          #+#    #+#             */
/*   Updated: 2020/02/04 12:29:48 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

char	*ft_substr(char const *s, unsigned int start, int len)
{
	int		i;
	char	*copy;

	i = 0;
	while (s[i + start] && i < len)
		i++;
	if (len > i)
		len = i;
	if (!(copy = (char *)malloc(len + 1)))
		return (NULL);
	i = -1;
	while (++i < len)
		copy[i] = s[start + i];
	copy[i] = '\0';
	return (copy);
}
