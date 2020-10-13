#include "get_next_line.h"

int		ft_strlen(char *str)
{
	int i = 0;
	while(str[i])
		i++;
	return(i);
}

char	*strjoinfree(char *s1, char *s2)
{
	int i = 0;
	int j = 0;
	char *newstr;

	if(!(newstr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return(NULL);
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

char	*strcpy(char *str)
{
	char *newstr;
	int i;
	int len;

	while(str[len] != '\n' && str[len])
		len++;
	if(!(newstr = malloc(sizeof(char) * (len + 1))))
		return(NULL);
	while (i < len)
	{
		newstr[i] = str[i];
		i++;
	}
	newstr[i] = '\0';
	return(newstr);
}

int		checkbuffer(char *buffer)
{
	int i = -1;

	while (buffer[++i])
		if (buffer[i] = '\n')
			return(1);
	return(0);
}

void	udpatebuffer(char **buffer)
{
	int i = 0;
	int j = 0;

	while((*buffer)[i] != '\n' && (*buffer)[i] != '\0')
		i++;
	if((*buffer)[i] == '\n')
	{
		i++;
		while((*buffer)[i+j])
		{
			(*buffer)[j] = (*buffer)[i + j];
			j++;
		}
		(*buffer)[j] = '\0';
	}
}

int		get_next_line(char **line)
{
	static char *buffer;
	char		*tmp;
	int			ret;
	int			buffer_size = 300;

	if(!line)
		return(-1);
	if(!buffer)
	{
		if(!(buffer = malloc(sizeof(char) * buffer_size + 1)))
			return(-1);
		buffer[0] = 0;
	}
	*line = strcpy(buffer);
	if(*line == NULL)
		return(-1);
	if (checkbuffer(buffer))
	{
		udpatebuffer(&buffer);
		return(1);
	}
	while(ret = read(0, buffer, buffer_size))
	{
		buffer[ret] = '\0';
		if(!checkbuffer(buffer))
		{
			*line = strjoinfree(*line, buffer);
			if(*line == NULL)
				return(-1);
		}
		else
		{
			tmp = strjoinfree(*line, buffer);
			*line = strcpy(tmp);
			free(tmp);
			if(*line == NULL)
				return(-1);
			udpatebuffer(&buffer);
			return(1);
		}
		
	}
	free(buffer);
	buffer = NULL;
	return(0);
}
