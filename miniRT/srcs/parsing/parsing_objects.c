/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_objects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 13:48:37 by cmeunier          #+#    #+#             */
/*   Updated: 2020/03/10 17:26:05 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

void	sphere_parsing(t_scene *scene, char *line)
{
	t_sphere	*sphere;
	int			i;

	i = 2;
	if(!(sphere = (malloc(sizeof(t_sphere)))))
		exit(0); // MALLOC PROBLEM
	skip_spaces(&i, line);
	sphere->pos = get_vec(&i, line);
	skip_spaces(&i, line);
	if((sphere->r = ft_atoi_double(&line[i])) < 0)
		exit(0); // check lum negative
	skip_numbers(&i, line);
	skip_spaces(&i, line);
	sphere->color = get_color(&i, line);
	// BONUS
	skip_spaces(&i, line);
	if((sphere->specular = ft_atoi_double(&line[i])) < 0)
		exit(0); // specular cannot have negative value
	add_back_obj(&scene->objects, sphere, (int)'s');
}

void	plane_parsing(t_scene *scene, char *line)
{
	t_plane	*plane;
	int			i;

	i = 2;
	if(!(plane = (malloc(sizeof(t_plane)))))
		exit(0); // MALLOC PROBLEM
	skip_spaces(&i, line);
	plane->pos = get_vec(&i, line);
	skip_spaces(&i, line);
	plane->rot = get_vec(&i, line);
	skip_spaces(&i, line);
	plane->color = get_color(&i, line);
	skip_spaces(&i, line);
	if((plane->specular = ft_atoi_double(&line[i])) < 0)
		exit(0); // specular cannot have negative value
	init_vec(&plane->normal, 0, 1, 0);
	rotation_calc(&plane->normal, plane->rot);
	add_back_obj(&scene->objects, plane, (int)'p');

}

void	square_parsing(t_scene *scene, char *line)
{
	t_square	*square;
	int			i;

	i = 2;
	if(!(square = (malloc(sizeof(t_square)))))
		exit(0); // MALLOC PROBLEM
	skip_spaces(&i, line);
	square->pos = get_vec(&i, line);
	skip_spaces(&i, line);
	square->rot = get_vec(&i, line);
	skip_spaces(&i, line);
	if((square->height = ft_atoi_double(&line[i])) < 0)
		exit(0); // specular cannot have negative value
	skip_numbers(&i, line);
	skip_spaces(&i, line);
	square->color = get_color(&i, line);
	skip_spaces(&i, line);
	init_vec(&square->normal, 0, 0, 1);
	rotation_calc(&square->normal, square->rot);
	if((square->specular = ft_atoi_double(&line[i])) < 0)
		exit(0); // specular cannot have negative value
	add_square_points(square);
	add_back_obj(&scene->objects, square, (int)'S');	
}

void	triangle_parsing(t_scene *scene, char *line)
{
	t_triangle	*triangle;
	int			i;

	i = 2;
	if(!(triangle = (malloc(sizeof(t_triangle)))))
		exit(0); // MALLOC PROBLEM
	skip_spaces(&i, line);
	triangle->point_1 = get_vec(&i, line);
	skip_spaces(&i, line);
	triangle->point_2 = get_vec(&i, line);
	skip_spaces(&i, line);
	triangle->point_3 = get_vec(&i, line);
	skip_spaces(&i, line);
	triangle->color = get_color(&i, line);
	skip_spaces(&i, line);
	if((triangle->specular = ft_atoi_double(&line[i])) < 0)
		exit(0); // specular cannot have negative value
	triangle->normal = normalized(cross_vec(sub_vec(triangle->point_1, triangle->point_2),
											sub_vec(triangle->point_1, triangle->point_3)));
	add_back_obj(&scene->objects, triangle, (int)'t');
}

void	cylinder_parsing(t_scene *scene, char *line)
{
	t_cylinder	*cylinder;
	int			i;

	i = 2;
	if(!(cylinder = (malloc(sizeof(t_cylinder)))))
		exit(0); // MALLOC PROBLEM
	init_vec(&cylinder->dir, 0, 1, 0);
	skip_spaces(&i, line);
	cylinder->pos = get_vec(&i, line);
	skip_spaces(&i, line);
	cylinder->rot = get_vec(&i, line);
	skip_spaces(&i, line);
	if((cylinder->diameter = ft_atoi_double(&line[i])) < 0)
		exit(0); // specular cannot have negative value
	skip_numbers(&i, line);
	skip_spaces(&i, line);
	if((cylinder->height = ft_atoi_double(&line[i])) < 0)
		exit(0); // specular cannot have negative value
	skip_numbers(&i, line);
	skip_spaces(&i, line);
	cylinder->color = get_color(&i, line);
	skip_spaces(&i, line);
	if((cylinder->specular = ft_atoi_double(&line[i])) < 0)
		exit(0); // specular cannot have negative value
	rotation_calc(&cylinder->dir, cylinder->rot);
	cylinder->pos2 = add_vec(cylinder->pos, mult_point_d(cylinder->dir, cylinder->height));
	cylinder->r = cylinder->diameter / 2;
	add_back_obj(&scene->objects, cylinder, (int)'c');
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

void	add_back_obj(t_objects **start, void *obj, int id)
{
	t_objects *ptr;
	t_objects *new;
	
	new = NULL;

	//initialise object
	if(!(new = (malloc(sizeof(t_objects)))))
		return ;
	new->id = id;
	new->obj = obj;
	new->next = NULL;
	//adding object to the linked list
	if(!*start)
	{	
		*start = new;
		return ;
	}
	ptr = *start;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = new;
}
