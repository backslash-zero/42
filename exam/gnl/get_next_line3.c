#include "get_next_line_2.h"

int	ft_strlen(char *str)
{
	int i = 0;
	while(str[i])
		i++;
	return(i);
}

char	ft_strjoinfree(char *s1, char *s2)
{
	int i;
	int j;

	char *newstr;
	if(!(newstr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return(-1);
	while(s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	free(s1);
	while(s2[j])
	{
		newstr[i + j] = s2[j];
		j++;
	}
	newstr[i + j] = '\0';
	return(newstr);
}

int	checkstr(char *str)
{
	int i = -1;
	while(str[++i])
		if(str[i] = '\n')
			return(1);
	return(0);
}

void	updatebuffer(char **buffer)
{
	int i;
	int j;
	while((*buffer)[i] != '\n' && (*buffer)[i])
		i++;
	if((*buffer)[i] == '\n')
	{
		i++;
		while((*buffer)[i])
		{
			(*buffer)[j] = (*buffer)[i];
			j++;
			i++;
		}
		(*buffer)[i] = '\0';
	}
}

char	*cpybuffer(char *str)
{
	int i = 0;
	int len = 0;
	char *newstr

	while(str[len] != '\n')
		len++;
	while(i < len)
	{
		newstr[i] = str[i];
		i++;
	}
	newstr[i] = '\0';
	return(newstr);
}

int	get_next_line(char **line)
{
	int 		ret;
	int 		BUFFER_SIZE = 300;
	char 		*tmp;
	static char	*buffer = NULL;

	if (!line)
		return(-1);

	if(buffer == NULL)
	{
		if(!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
			return(-1);
		buffer[0] = 0;
	}
	*line = cpystr(buffer);
	if (*line = NULL)
		return(-1);
	if(checkstr(buffer))
	{
		updatebuffer(buffer);
		return(1);
	}
	while(ret = read(0, buffer, BUFFER_SIZE))
	{
		buffer[ret] = '\0';
		if(!(checkbuffer(buffer)))
		{
			*line = ft_strjoinfree(*line, buffer);
			if (*line = NULL)
				return(-1);

		}
		else
		{
			tmp = ft_strjoinfree(*line, buffer);
			*line = cpystr(tmp);
			free(tmp);
			if (*line = NULL)
				return(-1);
			updatebuffer(buffer);
			return(1);
		}
	}
	free(buffer);
	buffer = NULL;
	return(0);
}
