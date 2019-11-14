/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 19:09:17 by cmeunier          #+#    #+#             */
/*   Updated: 2019/11/14 14:30:22 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int		ft_strlen(const char *s)
{
	int l;

	l = 0;
	if (!s)
		return (0);
	while (s[l])
		l++;
	return (l);
}

char	*ft_substr(char const *s, unsigned int start, int len)
{
	char	*str;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= (unsigned int)ft_strlen(s))
	{
		if (!(str = malloc(sizeof(char))))
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (len-- > 0)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

int		get_line_break(char *str)
{
	int i;

	i = -1;
	if (str == NULL)
		return (-1);
	while (str[++i])
		if (str[i] == '\n')
			return (i);
	return (-1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	if (!(new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	if (!s1)
	{
		while (s2[k])
			new[i++] = s2[k++];
		return (new);
	}
	while (s1[j])
		new[i++] = s1[j++];
	while (s2[k])
		new[i++] = s2[k++];
	new[i] = '\0';
	return (new);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	int		size;
	char	*str;

	i = 0;
	size = 0;
	while (s1[size])
		size += 1;
	str = (char*)malloc(sizeof(*str) * size + 1);
	if (str == NULL)
		return (NULL);
	while (i < size)
	{
		str[i] = s1[i];
		i++;
	}
	str[size] = '\0';
	return (str);
}

int		new_line(char **tmp, char **line, int ifend)
{
	int		len;
	char	*aux;

	if (ifend)
	{
		if (*tmp)
		{
			*line = ft_substr(*tmp, 0, ft_strlen(*tmp));
			aux = *line;
			free(aux);
			*tmp = NULL;
		}
	}
	else
	{
		if ((len = get_line_break(*tmp)) >= 0)
		{
			*line = ft_substr(*tmp, 0, len);
			if (len < ft_strlen(*tmp))
			{
				aux = *tmp;
				*tmp = ft_substr(*tmp, len + 1, ft_strlen(*tmp));
				free(aux);
				aux = *tmp;
				free(aux);
			}
			else
				*tmp = NULL;
			return (1);
		}
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	char		*buffer;
	static char	*tmp;
	int			ret;

	if (!fd || BUFFER_SIZE == 0 || !line
		|| !(buffer = malloc((sizeof(char) * (BUFFER_SIZE + 1)))))
		return (-1);
	buffer[BUFFER_SIZE] = '\0';
	if (new_line(&tmp, line, 0))
	{
		free(buffer);
		return (1);
	}
	while ((ret = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		tmp = ft_strjoin(tmp, buffer);
		if (new_line(&tmp, line, 0))
		{
			free(buffer);
			return (1);
		}
	}
	free(buffer);
	return ret < 0 ? -1 : new_line(&tmp, line, 1);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		retour;
	int		i;

	i = 1;
	(void)argc;
	fd = open(argv[1], O_RDONLY);
	while ((retour = get_next_line(fd, &line)) > 0)
	{
		printf("%d:%d	%s\n",retour,  i, line);
		i++;
		free(line);
	}
	printf("%d:%d	%s\n",retour,  i, line);
	close(fd);
}
