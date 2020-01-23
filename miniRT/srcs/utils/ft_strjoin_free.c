/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 16:47:25 by cmeunier          #+#    #+#             */
/*   Updated: 2020/01/23 17:32:09 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*new;
	int		len_s1;
	int		len_s2;
	int		i;

	len_s1 = 0;
	len_s2 = 0;
	i = -1;
	if (s1)
		while (s1[len_s1])
			len_s1++;
	while (s2[len_s2])
		len_s2++;
	if ((new = (char *)malloc(len_s1 + len_s2 + 1)) == NULL)
		return (NULL);
	while (++i < len_s1)
		new[i] = s1[i];
	i = -1;
	while (++i < len_s2)
		new[len_s1 + i] = s2[i];
	new[len_s1 + len_s2] = '\0';
	free(s1);
	return (new);
}
