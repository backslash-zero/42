/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RT_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:36:40 by cmeunier          #+#    #+#             */
/*   Updated: 2020/03/12 13:51:23 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_UTILS_H
# define RT_UTILS_H

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
int		ft_atoi(const char *str);
int		is_whitespace(char c);
int		is_plusminus(char c);
int		is_digit(char c);
double	ft_atoi_decimal(char *str);
double	ft_atoi_double(char *str);
void	exit_free_all(t_scene *scene);
void	free_cameras(t_cameras *cameras);
void	free_objects(t_objects *objects);
void	free_lights(t_lights *lights);
char	*ft_itoa(int n);

#endif
