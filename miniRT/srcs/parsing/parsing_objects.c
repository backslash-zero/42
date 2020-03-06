/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_objects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 13:48:37 by cmeunier          #+#    #+#             */
/*   Updated: 2020/03/06 12:03:05 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

void	sphere_parsing(t_scene *scene, const char *line)
{

}

void	square_parsing(t_scene *scene, const char *line)
{

}

void	cylinder_parsing(t_scene *scene, const char *line)
{

}

void	triangle_parsing(t_scene *scene, const char *line)
{

}

void	plane_parsing(t_scene *scene, const char *line)
{

}

void	object_parsing(t_objects **objects)
{
	// open fd and use get next line until return value is 0
	// use main from GNL

	/* ************************************************************************** */
	/*	Custom obects															  */	
	/* ************************************************************************** */
	
	*objects = NULL;
	t_sphere *sphere_0;
	t_sphere *sphere_1;
	t_sphere *sphere_2;
	t_sphere *sphere_3;
	t_sphere *sphere_4;
	t_sphere *sphere_5;
	t_sphere *sphere_6;
	
	if(!(sphere_0 = (malloc(sizeof(t_sphere)))))
		return ;
	if(!(sphere_1 = (malloc(sizeof(t_sphere)))))
		return ;
	if(!(sphere_2 = (malloc(sizeof(t_sphere)))))
		return ;
	if(!(sphere_3 = (malloc(sizeof(t_sphere)))))
		return ;
	if(!(sphere_4 = (malloc(sizeof(t_sphere)))))
		return ;
	if(!(sphere_5 = (malloc(sizeof(t_sphere)))))
		return ;
	if(!(sphere_6 = (malloc(sizeof(t_sphere)))))
		return ;
	//exit if sphere was not allocated?

	// add sphere to objects
	sphere_0->pos.x = 0;
	sphere_0->pos.y = 0;
	sphere_0->pos.z = 0;
	sphere_0->r = 3;
	sphere_0->specular = 100;
	sphere_0->color = assign_colors(76, 44, 114);
	add_back_obj(objects, sphere_0, (int)'s');

	sphere_1->pos.x = 4;
	sphere_1->pos.y = 0;
	sphere_1->pos.z = 0;
	sphere_1->r = 1;
	sphere_1->specular = 100;
	sphere_1->color = assign_colors(156, 227, 125);
	add_back_obj(objects, sphere_1, (int)'s');
	
	sphere_2->pos.x = -4;
	sphere_2->pos.y = 0;
	sphere_2->pos.z = 0;
	sphere_2->r = 1;
	sphere_2->specular = 200;
	sphere_2->color = assign_colors(116, 139, 117);
	add_back_obj(objects, sphere_2, (int)'s');

	sphere_3->pos.x = 0;
	sphere_3->pos.y = 4;
	sphere_3->pos.z = 0;
	sphere_3->r = 1;
	sphere_3->specular = 20;
	sphere_3->color = assign_colors(233, 210, 192);
	add_back_obj(objects, sphere_3, (int)'s');

	sphere_4->pos.x = 0;
	sphere_4->pos.y = -50;
	sphere_4->pos.z = 0;
	sphere_4->r = 50;
	sphere_4->specular = 1;
	sphere_4->color = assign_colors(233, 210, 192);
	add_back_obj(objects, sphere_4, (int)'s');

	sphere_5->pos.x = 15;
	sphere_5->pos.y = 0;
	sphere_5->pos.z = 0;
	sphere_5->r = 3;
	sphere_5->specular = 30;
	sphere_5->color = assign_colors(202, 156, 225);
	add_back_obj(objects, sphere_5, (int)'s');

	sphere_6->pos.x = -15;
	sphere_6->pos.y = 0;
	sphere_6->pos.z = 0;
	sphere_6->r = 3;
	sphere_6->specular = 3;
	sphere_6->color = assign_colors(104, 95, 116);
	add_back_obj(objects, sphere_6, (int)'s');

	// MAKE SURE TO HAVE DEFAULT ORIENTATION TO PLANES
	t_plane *plane_0;
	if(!(plane_0 = (malloc(sizeof(t_plane)))))
		return ;
	init_vec(&plane_0->pos, 0, -2, 0);
	init_vec(&plane_0->rot, 0, 1, 0);
	plane_0->normal = plane_0->rot;
	plane_0->specular = 114;
	plane_0->color = assign_colors(243, 224, 236);
	add_back_obj(objects, plane_0, (int)'p');

	t_square *square_0;
	if(!(square_0 = (malloc(sizeof(t_square)))))
		return ;
	init_vec(&square_0->pos, 0, 6, 0);
	init_vec(&square_0->rot, 0.5, 0.25, 0);
	init_vec(&square_0->normal, 0, 0, 1);
	rotation_calc(&square_0->normal, square_0->rot);
	square_0->height = 1;
	square_0->specular = 114;
	square_0->color = assign_colors(255, 0, 0);
	add_square_points(square_0);
	add_back_obj(objects, square_0, (int)'S');
	
	/* ************************************************************************** */
	/* ************************************************************************** */

	t_triangle *triangle_0;
	if(!(triangle_0 = (malloc(sizeof(t_triangle)))))
		return ;
	init_vec(&triangle_0->point_1, -4, 0, 2);
	init_vec(&triangle_0->point_2, -4, 5, 0);
	init_vec(&triangle_0->point_3, -4, 0, -2);
	triangle_0->color = assign_colors(202, 156, 255);
	triangle_0->specular = 114;
	add_back_obj(objects, triangle_0, (int)'t');

	/* ************************************************************************** */
	/* ************************************************************************** */
	
	t_cylinder *cylinder_0;
	if(!(cylinder_0 = (malloc(sizeof(t_cylinder)))))
		return ;
	init_vec(&cylinder_0->pos, 0, 3, 5);
	init_vec(&cylinder_0->dir, 0, 0, 1);
	init_vec(&cylinder_0->rot, 0.5, 0.25, 0);
	cylinder_0->color = assign_colors(202, 156, 255);
	cylinder_0->specular = 114;
	cylinder_0->diameter = 3;
	cylinder_0->height = 2;
	cylinder_0->r = cylinder_0->diameter /2;
	rotation_calc(&cylinder_0->dir, cylinder_0->rot);
	cylinder_0->pos2 = add_vec(cylinder_0->pos, mult_point_d(cylinder_0->dir, cylinder_0->height));
	add_back_obj(objects, cylinder_0, (int)'c');
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
