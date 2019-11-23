/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:04:44 by cmeunier          #+#    #+#             */
/*   Updated: 2019/11/23 16:05:11 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *b, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char*)b;
	while (n-- > 0)
		*(ptr++) = 0;
}

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

int		get_line_break(const char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
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
