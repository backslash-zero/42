/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_objects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 13:48:37 by cmeunier          #+#    #+#             */
/*   Updated: 2020/03/11 20:08:10 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

void	sphere_parsing(t_rt *rt, char *line, int n)
{
	t_sphere	*sphere;
	int			i;

	i = 2;
	if(!(sphere = (malloc(sizeof(t_sphere)))))
		exit_failure(rt);
	skip_spaces(&i, line);
	sphere->pos = get_vec(&i, line);
	skip_spaces(&i, line);
	if((sphere->r = ft_atoi_double(&line[i])) < 0)
		parsing_err(rt, "Radius cannot be negative", n);
	skip_numbers(&i, line);
	skip_spaces(&i, line);
	sphere->color = get_color(rt, &i, line, n);
	skip_spaces(&i, line);
	if((sphere->specular = ft_atoi_double(&line[i])) < 0)
		parsing_err(rt, "Luminosity must be set betweem 0 and 1", n);
	if(add_back_obj(&rt->scene->objects, sphere, (int)'s') == FAILURE)
		exit_failure(rt);
}

void	plane_parsing(t_rt *rt, char *line, int n)
{
	t_plane	*plane;
	int			i;

	i = 2;
	if(!(plane = (malloc(sizeof(t_plane)))))
		exit_failure(rt);
	skip_spaces(&i, line);
	plane->pos = get_vec(&i, line);
	skip_spaces(&i, line);
	plane->rot = get_vec(&i, line);
	skip_spaces(&i, line);
	plane->color = get_color(rt, &i, line, n);
	skip_spaces(&i, line);
	if((plane->specular = ft_atoi_double(&line[i])) < 0)
		parsing_err(rt, "Luminosity must be set betweem 0 and 1", n);
	init_vec(&plane->normal, 0, 1, 0);
	rotation_calc(&plane->normal, plane->rot);
	if(add_back_obj(&rt->scene->objects, plane, (int)'p') == FAILURE)
		exit_failure(rt);

}

void	square_parsing(t_rt *rt, char *line, int n)
{
	t_square	*square;
	int			i;

	i = 2;
	if(!(square = (malloc(sizeof(t_square)))))
		exit_failure(rt);
	skip_spaces(&i, line);
	square->pos = get_vec(&i, line);
	skip_spaces(&i, line);
	square->rot = get_vec(&i, line);
	skip_spaces(&i, line);
	if((square->height = ft_atoi_double(&line[i])) < 0)
		parsing_err(rt, "Height cannot be negative", n);
	skip_numbers(&i, line);
	skip_spaces(&i, line);
	square->color = get_color(rt, &i, line, n);
	skip_spaces(&i, line);
	init_vec(&square->normal, 0, 0, 1);
	rotation_calc(&square->normal, square->rot);
	if((square->specular = ft_atoi_double(&line[i])) < 0)
		parsing_err(rt, "Luminosity must be set betweem 0 and 1", n);
	add_square_points(square);
	if(add_back_obj(&rt->scene->objects, square, (int)'S') == FAILURE)
		exit_failure(rt);
}

void	triangle_parsing(t_rt *rt, char *line, int n)
{
	t_triangle	*triangle;
	int			i;

	i = 2;
	if(!(triangle = (malloc(sizeof(t_triangle)))))
		exit_failure(rt);
	skip_spaces(&i, line);
	triangle->point_1 = get_vec(&i, line);
	skip_spaces(&i, line);
	triangle->point_2 = get_vec(&i, line);
	skip_spaces(&i, line);
	triangle->point_3 = get_vec(&i, line);
	skip_spaces(&i, line);
	triangle->color = get_color(rt, &i, line, n);
	skip_spaces(&i, line);
	if((triangle->specular = ft_atoi_double(&line[i])) < 0)
		parsing_err(rt, "Luminosity must be set betweem 0 and 1", n);
	triangle->normal = normalized(cross_vec(sub_vec(triangle->point_1, triangle->point_2),
											sub_vec(triangle->point_1, triangle->point_3)));
	if(add_back_obj(&rt->scene->objects, triangle, (int)'t') == FAILURE)
		exit_failure(rt);
}

void	cylinder_parsing(t_rt *rt, char *line, int n)
{
	t_cylinder	*cylinder;
	int			i;

	i = 2;
	if(!(cylinder = (malloc(sizeof(t_cylinder)))))
		exit_failure(rt);
	init_vec(&cylinder->dir, 0, 1, 0);
	skip_spaces(&i, line);
	cylinder->pos = get_vec(&i, line);
	skip_spaces(&i, line);
	cylinder->rot = get_vec(&i, line);
	skip_spaces(&i, line);
	if((cylinder->diameter = ft_atoi_double(&line[i])) < 0)
		parsing_err(rt, "Diameter cannot be negative", n);
	skip_numbers(&i, line);
	skip_spaces(&i, line);
	if((cylinder->height = ft_atoi_double(&line[i])) < 0)
		parsing_err(rt, "Height cannot be negative", n);
	skip_numbers(&i, line);
	skip_spaces(&i, line);
	cylinder->color = get_color(rt, &i, line, n);
	skip_spaces(&i, line);
	if((cylinder->specular = ft_atoi_double(&line[i])) < 0)
		parsing_err(rt, "Luminosity must be set betweem 0 and 1", n);
	rotation_calc(&cylinder->dir, cylinder->rot);
	cylinder->pos2 = add_vec(cylinder->pos, mult_point_d(cylinder->dir, cylinder->height));
	cylinder->r = cylinder->diameter / 2;
	if(add_back_obj(&rt->scene->objects, cylinder, (int)'c') == FAILURE)
		exit_failure(rt);
}

void	add_square_points(t_square *square_0)
{
	// rotate normal
	t_vec	i;
	t_vec	j;

	init_vec(&i, square_0->height / 2, 0, 0);
	init_vec(&j, 0, square_0->height / 2, 0);
	rotation_calc(&i, square_0->rot);
	rotation_calc(&j, square_0->rot);
	square_0->point_1 = add_vec(square_0->pos, add_vec(j, mult_point_d(i, -1)));
	square_0->point_2 = add_vec(square_0->pos, add_vec(j, i));
	square_0->point_3 = add_vec(square_0->pos, add_vec(mult_point_d(j, -1), i));
	square_0->point_4 = add_vec(square_0->pos, add_vec(mult_point_d(j, -1), mult_point_d(i, -1)));
}

int		add_back_obj(t_objects **start, void *obj, int id)
{
	t_objects *ptr;
	t_objects *new;
	
	new = NULL;
	if(!(new = (malloc(sizeof(t_objects)))))
		return(FAILURE);
	new->id = id;
	new->obj = obj;
	new->next = NULL;
	if(!*start)
	{	
		*start = new;
		return ;
	}
	ptr = *start;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = new;
	return(SUCCESS);
}
