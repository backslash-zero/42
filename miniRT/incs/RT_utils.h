/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RT_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:36:40 by cmeunier          #+#    #+#             */
/*   Updated: 2020/03/02 16:27:48 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_UTILS_H
# define RT_UTILS_H

# include "miniRT.h"

size_t	ft_strlen(const char *s);
void	ft_bzero(void *b, size_t n);
char	*ft_strjoin_free(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, int len);
int		get_line_break(const char *str);
int		ft_error_gnl(char **line, char **buffer);
int		ft_read_line(int fd, char **buffer, char **line);
int		ft_finish_line(char **save, char **line, char *buffer, int ret);
int		get_next_line(int fd, char **line);

#endif