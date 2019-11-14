/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:03:39 by cmeunier          #+#    #+#             */
/*   Updated: 2019/10/30 14:47:16 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);
char    *ft_strjoin(char const *s1, char const *s2);
void    ft_bzero(void *s, size_t n);
size_t  ft_strlen(const char *s);
void    *ft_memset(void *b, int c, size_t len);
void    *ft_calloc(size_t count, size_t size);
char    *ft_substr(char const *s, unsigned int start, size_t len);

#endif