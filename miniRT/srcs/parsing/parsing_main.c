/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 17:57:51 by cmeunier          #+#    #+#             */
/*   Updated: 2020/03/05 18:37:22 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

int		p_test_window(const char *line)
{
	if(line[0] == 'R')
		return (1);
	else
		return (0);	
}

int		p_test_camera(const char *line)
{
	if(line[0] == 'c' && line[1] != 'y' )
		return (1);
	else
		return (0);	
}

int		p_test_sphere(const char *line)
{
	if((line[0] == 's' && line[1] == 'p' ))
		return (1);
	else
		return (0);	
}
int		p_test_plane(const char *line)
{
	if((line[0] == 'p' && line[1] == 'l' ))
		return (1);
	else
		return (0);	
}
int		p_test_square(const char *line)
{
	if((line[0] == 's' && line[1] == 'q' ))
		return (1);
	else
		return (0);	
}
int		p_test_cylinder(const char *line)
{
	if((line[0] == 'c' && line[1] == 'y' ))
		return (1);
	else
		return (0);	
}
int		p_test_triangle(const char *line)
{
	if((line[0] == 't' && line[1] == 'r' ))
		return (1);
	else
		return (0);	
}

int		p_test_point_light(const char *line)
{
	if(line[0] == 'l')
		return (1);
	else
		return (0);	
}

int		p_test_ambient_light(const char *line)
{
	if(line[0] == 'A')
		return (1);
	else
		return (0);	
}

void	main_parser(t_scene *scene, const char *line)
{
	//check if line empty
	if(p_test_window(line))
		window_parsing(scene);
	if(p_test_sphere(line))
		sphere_parsing(scene, line);
	if(p_test_square(line))
		square_parsing(scene, line);
	if(p_test_cylinder(line))
		cylinder_parsing(scene, line);	
	if(p_test_triangle(line))
		triangle_parsing(scene, line);
	if(p_test_plane(line))
		plane_parsing(scene, line);
	if(p_test_point_light(line))
		point_light_parsing(scene, line);
	if(p_test_ambient_light(line))
		ambient_light_parsing(scene, line);
	if(p_test_camera(line))

	///ELSE ERROR KEY ASSIGNED IS WRONG
}
