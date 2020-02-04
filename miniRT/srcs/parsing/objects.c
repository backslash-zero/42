/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:03:19 by cmeunier          #+#    #+#             */
/*   Updated: 2020/02/04 14:54:52 by cmeunier         ###   ########.fr       */
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
	printf("\n Check 0\n");
	*objects = NULL;
	t_sphere *sphere_0;
	t_sphere *sphere_1;
	t_sphere *sphere_2;

	printf("\n Check 1\n");
	if(!(sphere_0 = (malloc(sizeof(t_sphere)))))
		return ;
	if(!(sphere_1 = (malloc(sizeof(t_sphere)))))
		return ;
	if(!(sphere_2 = (malloc(sizeof(t_sphere)))))
		return ;
	//exit if sphere was not allocated?

	printf("\n Check 2\n");

	// add sphere to objects
	sphere_0->pos.x = 0;
	sphere_0->pos.y = -1;
	sphere_0->pos.z = 3;
	sphere_0->r = 1;
	sphere_0->color = get_color_integer(0, 3, 104);
	
	printf("\n Check 3\n");

	add_back_obj(objects, sphere_0, (int)'s');

	printf("\n Check 4\n");
	sphere_1->pos.x = 2;
	sphere_1->pos.y = 0;
	sphere_1->pos.z = 4;
	sphere_1->r = 1;
	sphere_1->color = get_color_integer(224, 5, 11);
	
	add_back_obj(objects, sphere_1, (int)'s');
	
	sphere_2->pos.x = -2;
	sphere_2->pos.y = 0;
	sphere_2->pos.z = 4;
	sphere_2->r = 1;
	sphere_2->color = get_color_integer(33, 255, 2);
	
	add_back_obj(objects, sphere_2, (int)'s');

	/* ************************************************************************** */
	/*	End Custom obects														  */	
	/* ************************************************************************** */
}

void	add_back_obj(t_objects **start, void *obj, int id)
{
	t_objects *ptr;
	t_objects *new;
	
	new = NULL;
	printf("\n Check 5\n");
	//initialise object
	if(!(new = (malloc(sizeof(t_objects)))))
		return ;
	new->id = id;
	new->obj = obj;
	new->next = NULL;
	printf("\n Check 6\n");
	printf("\n **start: %p\n", start);
	printf("\n *start: %p\n", *start);
	//adding object to the linked list
	if(!*start)
	{
		printf("\n HERE\n");
		*start = new;
		return ;
	}
	printf("\n Check 7\n");
	ptr = *start;
	printf("\n Check 8\n");
	while (ptr->next)
		ptr = ptr->next;
	printf("\n Check 9\n");
	ptr->next = new;
	printf("\n Check 10\n");
}
