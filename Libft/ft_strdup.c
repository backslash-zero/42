/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:21:33 by cmeunier          #+#    #+#             */
/*   Updated: 2019/10/22 12:16:50 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*new;
	int		i;

	i = 0;
	len = ft_strlen(s1) + 1;
	if (!(new = ft_calloc(1, len * sizeof(char))))
		return (NULL);
	ft_strlcpy(new, s1, len);
	return (new);
}
