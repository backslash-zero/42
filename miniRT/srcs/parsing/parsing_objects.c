/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_objects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 13:48:37 by cmeunier          #+#    #+#             */
/*   Updated: 2020/03/12 17:56:48 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minirt.h"

void	sphere_parsing(t_rt *rt, char *line, int n)
{
	t_sphere	*sphere;
	int			i;

	i = 2;
	if (!(sphere = (malloc(sizeof(t_sphere)))))
		exit_failure(rt);
	skip_spaces(&i, line);
	sphere->pos = get_vec(rt, &i, line, n);
	skip_spaces(&i, line);
	if ((sphere->r = ft_atoi_double(&line[i])) < 0)
		parsing_err(rt, "Radius cannot be negative", n);
	skip_numbers(&i, line);
	skip_spaces(&i, line);
	sphere->color = get_color(rt, &i, line, n);
	skip_spaces(&i, line);
	if ((sphere->specular = ft_atoi_double(&line[i])) < 0)
		parsing_err(rt, "Luminosity must be set betweem 0 and 1", n);
	if (add_back_obj(&rt->scene->objects, sphere, (int)'s') == FAILURE)
		exit_failure(rt);
}

void	plane_parsing(t_rt *rt, char *line, int n)
{
	t_plane	*plane;
	int		i;

	i = 2;
	if (!(plane = (malloc(sizeof(t_plane)))))
		exit_failure(rt);
	skip_spaces(&i, line);
	plane->pos = get_vec(rt, &i, line, n);
	skip_spaces(&i, line);
	plane->rot = get_vec(rt, &i, line, n);
	skip_spaces(&i, line);
	plane->color = get_color(rt, &i, line, n);
	skip_spaces(&i, line);
	if ((plane->specular = ft_atoi_double(&line[i])) < 0)
		parsing_err(rt, "Luminosity must be set betweem 0 and 1", n);
	init_vec(&plane->normal, 0, 1, 0);
	rotation_calc(&plane->normal, plane->rot);
	if (add_back_obj(&rt->scene->objects, plane, (int)'p') == FAILURE)
		exit_failure(rt);
}

void	square_parsing(t_rt *rt, char *line, int n)
{
	t_square	*square;
	int			i;

	i = 2;
	if (!(square = (malloc(sizeof(t_square)))))
		exit_failure(rt);
	skip_spaces(&i, line);
	square->pos = get_vec(rt, &i, line, n);
	skip_spaces(&i, line);
	square->rot = get_vec(rt, &i, line, n);
	skip_spaces(&i, line);
	if ((square->height = ft_atoi_double(&line[i])) < 0)
		parsing_err(rt, "Height cannot be negative", n);
	skip_numbers(&i, line);
	skip_spaces(&i, line);
	square->color = get_color(rt, &i, line, n);
	skip_spaces(&i, line);
	init_vec(&square->normal, 0, 0, 1);
	rotation_calc(&square->normal, square->rot);
	if ((square->specular = ft_atoi_double(&line[i])) < 0)
		parsing_err(rt, "Luminosity must be set betweem 0 and 1", n);
	add_square_points(square);
	if (add_back_obj(&rt->scene->objects, square, (int)'S') == FAILURE)
		exit_failure(rt);
}

void	triangle_parsing(t_rt *rt, char *line, int n)
{
	t_triangle	*triangle;
	int			i;

	i = 2;
	if (!(triangle = (malloc(sizeof(t_triangle)))))
		exit_failure(rt);
	skip_spaces(&i, line);
	triangle->point_1 = get_vec(rt, &i, line, n);
	skip_spaces(&i, line);
	triangle->point_2 = get_vec(rt, &i, line, n);
	skip_spaces(&i, line);
	triangle->point_3 = get_vec(rt, &i, line, n);
	skip_spaces(&i, line);
	triangle->color = get_color(rt, &i, line, n);
	skip_spaces(&i, line);
	if ((triangle->specular = ft_atoi_double(&line[i])) < 0)
		parsing_err(rt, "Luminosity must be set betweem 0 and 1", n);
	triangle->normal = normalized(cross_vec(sub_vec(triangle->point_1,
		triangle->point_2), sub_vec(triangle->point_1, triangle->point_3)));
	if (add_back_obj(&rt->scene->objects, triangle, (int)'t') == FAILURE)
		exit_failure(rt);
}

void	cylinder_parsing(t_rt *rt, char *line, int n, int i)
{
	t_cylinder	*cylinder;

	if (!(cylinder = (malloc(sizeof(t_cylinder)))))
		exit_failure(rt);
	init_vec(&cylinder->dir, 0, 1, 0);
	skip_spaces(&i, line);
	cylinder->pos = get_vec(rt, &i, line, n);
	skip_spaces(&i, line);
	cylinder->rot = get_vec(rt, &i, line, n);
	skip_spaces(&i, line);
	if ((cylinder->r = ft_atoi_double(&line[i]) / 2) < 0)
		parsing_err(rt, "Diameter cannot be negative", n);
	skip_nb_spaces(&i, line);
	if ((cylinder->height = ft_atoi_double(&line[i])) < 0)
		parsing_err(rt, "Height cannot be negative", n);
	skip_nb_spaces(&i, line);
	cylinder->color = get_color(rt, &i, line, n);
	skip_spaces(&i, line);
	if ((cylinder->specular = ft_atoi_double(&line[i])) < 0)
		parsing_err(rt, "Luminosity must be set betweem 0 and 1", n);
	rotation_calc(&cylinder->dir, cylinder->rot);
	cylinder->pos2 = add_vec(cylinder->pos,
					mult_point_d(cylinder->dir, cylinder->height));
	if (add_back_obj(&rt->scene->objects, cylinder, (int)'c') == FAILURE)
		exit_failure(rt);
}
