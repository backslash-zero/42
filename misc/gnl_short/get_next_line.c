#include "get_next_line.h"

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

char *strjoinfree(char *s1, char *s2)
{
	char	*new_str;
	int	len;
	int	i;
	int	j;

	len = ft_strlen(s1) + ft_strlen(s2);
	new_str = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	free(s1);
	j = 0;
	while (s2[j])
	{
		new_str[i + j] = s2[j];
		j++;
	}
	new_str[i + j] = '\0';
	return (new_str);
}

char *cpy_buff(char *buff)
{
	char *new_str;
	int len;
	int i;

	i = -1;
	len = 0;
	while (buff[len] != '\n' && buff[len] != '\0')
		len++;
	new_str = malloc(sizeof(char) * (len + 1));
	while (++i < len)
		new_str[i] = buff[i];
	new_str[len] = '\0';
	return (new_str);
}

int check_buff(char *buff)
{
	int i;

	i = -1;
	while (buff[++i])
		if (buff[i] == '\n')
			return (1);
	return (0);
}

void	save_buffer(char **buff)
{
	//"abc\ndef" => "def\0"
	int i;
	int j;

	i = 0;
	j = 0;
	while ((*buff)[i] != '\n' && (*buff)[i] != '\0')
		i++;
	if ((*buff)[i] == '\n')
	{
		i++;
		while ((*buff)[i + j] != '\0')
		{
			(*buff)[j] = (*buff)[i + j];
			j++;
		}
		(*buff)[j] = '\0';
	}
}

int get_next_line(char **line)
{
	static char	*buff = NULL;
	char		*tmp;
	int			ret;
	int			buff_size = 300;

	//system("leaks a.out | grep 'leaked'");
	if (!line)
		return (-1);
	if (!buff)
	{
		buff = malloc(sizeof(char) * (buff_size + 1));
		if (buff == NULL)
			return (-1);
		buff[0] = 0;
	}
	*line = cpy_buff(buff);//"abc\ndef" => "abc\0"
	if (*line == NULL)
		return (-1);
	//while (buff[i] != '\n' || buff[i] != '\0') OK
	if (check_buff(buff))
	{
		save_buffer(&buff); //"Hello Word\n Bonjour Monde" => " Bonjour Monde\0"
		return(1);
	}
	while ((ret = read(0, buff, buff_size)))
	{
		buff[ret] = '\0';
		if (check_buff(buff) == 0)
		{
			*line = strjoinfree(*line, buff);
			if (*line == NULL)
				return (-1);
		}
		else
		{
			tmp	= strjoinfree(*line, buff);
			*line = cpy_buff(tmp); //"abc\ndef" => "abc\0"
			free(tmp);
			if (*line == NULL)
				return (-1);
			save_buffer(&buff); //"abc\ndef" => "def\0"
			return (1);
		}
	}
	free(buff);
	buff = NULL;
	return (0);
}