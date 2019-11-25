/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 19:09:17 by cmeunier          #+#    #+#             */
/*   Updated: 2019/11/25 17:31:42 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

int		ft_error(char **line, char **buffer)
{
	free(*line);
	if (line && *line)
		*line = NULL;
	if (buffer)
		free(*buffer);
	if (buffer && *buffer)
		*buffer = NULL;
	return (-1);
}

int		ft_read_line(int fd, char **buffer, char **line)
{
	int r;
	int pos;

	while ((r = read(fd, *buffer, BUFFER_SIZE)) > 0)
	{
		pos = get_line_break(*buffer);
		if (pos < BUFFER_SIZE && buffer[0][pos])
			return (r);
		if (!(*line = ft_strjoin(*line, *buffer)))
			return (ft_error(line, NULL));
		ft_bzero(*buffer, BUFFER_SIZE + 1);
	}
	if (!r)
	{
		*line = ft_strjoin(*line, *buffer);
		return (0);
	}
	return (ft_error(line, NULL));
}

int		ft_finish_line(char **save, char **line, char *buffer, int ret)
{
	char	*str;
	int		pos;

	pos = get_line_break(buffer);
	if (!(str = ft_substr(buffer, 0, pos)))
		return (ft_error(line, &buffer));
	if (!(*line = ft_strjoin(*line, str)))
	{
		free(str);
		return (ft_error(line, &buffer));
	}
	free(str);
	if (buffer[pos])
		if (!(*save = ft_substr(buffer, pos + 1, BUFFER_SIZE - pos - 1)))
			return (ft_error(line, &buffer));
	pos = (buffer[pos] || ret == BUFFER_SIZE) ? 1 : 0;
	free(buffer);
	return (pos);
}

int		get_next_line(int fd, char **line)
{
	char		*buffer;
	static char	*save;
	int			ret;

	if (fd < 0 || BUFFER_SIZE < 1 || !line)
		return (-1);
	*line = NULL;
	if (save && save[get_line_break(save)])
		return (ft_finish_line(&save, line, save, BUFFER_SIZE));
	*line = save;
	save = NULL;
	if (!(buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	ft_bzero(buffer, BUFFER_SIZE + 1);
	if ((ret = ft_read_line(fd, &buffer, line)) < 1)
	{
		free(buffer);
		return (ret);
	}
	return (ft_finish_line(&save, line, buffer, ret));
}
