/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 23:44:00 by cmeunier          #+#    #+#             */
/*   Updated: 2020/02/27 17:25:52 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

void	ambient_light_parsing(t_scene *scene)
{
	scene->ambient_light.color = assign_colors(255, 255, 255);
	scene->ambient_light.lum = 0.8;
}

void	point_light_parsing(t_lights **lights)
{
	// open fd and use get next line until return value is 0
	// use main from GNL

	/* ************************************************************************** */
	/*	Custom obects															  */	
	/* ************************************************************************** */
	
	*lights = NULL;
	t_point_light *point_light_0;
	t_point_light *point_light_1;
	
	if(!(point_light_0 = (malloc(sizeof(t_point_light)))))
		return ;
	point_light_0->pos.x = -20;
	point_light_0->pos.y = 20;
	point_light_0->pos.z = 0;
	point_light_0->lum = 0.4;
	point_light_0->color = assign_colors(255, 0, 255);
	add_back_light(lights, point_light_0);

	if(!(point_light_1 = (malloc(sizeof(t_point_light)))))
		return ;
	point_light_1->pos.x = 20;
	point_light_1->pos.y = 20;
	point_light_1->pos.z = 0;
	point_light_1->lum = 0.5;
	point_light_1->color = assign_colors(255, 255, 0);
	add_back_light(lights, point_light_1);
}

void	add_back_light(t_lights **start, void *point_light)
{
	t_lights *ptr;
	t_lights *new;
	
	new = NULL;

	//initialise light
	if(!(new = (malloc(sizeof(t_lights)))))
		return ;
	new->point_light = point_light;
	new->next = NULL;
	//adding light to the linked list
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
