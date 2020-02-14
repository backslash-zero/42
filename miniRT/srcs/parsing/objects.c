/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:03:19 by cmeunier          #+#    #+#             */
/*   Updated: 2020/02/14 21:57:43 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

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
	sphere_0->pos.y = -1;
	sphere_0->pos.z = 12;
	sphere_0->r = 2;
	sphere_0->color = assign_colors(76, 44, 114);
	add_back_obj(objects, sphere_0, (int)'s');

	sphere_1->pos.x = 3;
	sphere_1->pos.y = 0;
	sphere_1->pos.z = 15;
	sphere_1->r = 2;
	sphere_1->color = assign_colors(156, 227, 125);
	add_back_obj(objects, sphere_1, (int)'s');
	
	sphere_2->pos.x = -2;
	sphere_2->pos.y = 0;
	sphere_2->pos.z = 10;
	sphere_2->r = 2;
	sphere_2->color = assign_colors(116, 139, 117);
	add_back_obj(objects, sphere_2, (int)'s');

	sphere_3->pos.x = 3;
	sphere_3->pos.y = 3;
	sphere_3->pos.z = 8;
	sphere_3->r = 1;
	sphere_3->color = assign_colors(233, 210, 192);
	add_back_obj(objects, sphere_3, (int)'s');

	sphere_4->pos.x = -5;
	sphere_4->pos.y = 5;
	sphere_4->pos.z = 20;
	sphere_4->r = 10;
	sphere_4->color = assign_colors(245, 251, 239);
	add_back_obj(objects, sphere_4, (int)'s');

	sphere_5->pos.x = 15;
	sphere_5->pos.y = 0;
	sphere_5->pos.z = 0;
	sphere_5->r = 3;
	sphere_5->color = assign_colors(255, 0, 0);
	add_back_obj(objects, sphere_5, (int)'s');

	sphere_6->pos.x = -15;
	sphere_6->pos.y = 0;
	sphere_6->pos.z = 0;
	sphere_6->r = 3;
	sphere_6->color = assign_colors(0, 0, 239);
	add_back_obj(objects, sphere_6, (int)'s');

	/* ************************************************************************** */
	/*	End Custom obects														  */	
	/* ************************************************************************** */
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
