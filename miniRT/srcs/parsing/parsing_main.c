/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 17:57:51 by cmeunier          #+#    #+#             */
/*   Updated: 2020/03/11 18:59:34 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

int		p_test_window(t_scene *scene, char *line)
{
	if(line[0] == 'R')
	{	
		if(scene->tracker.window)
			exit_free_all(scene); // Resolution assigned more than once
		else
		{
			scene->tracker.window = 1;
			return (1);
		}
	}
	return (0);	
}

int		p_test_camera(t_scene *scene, char *line)
{
	if(line[0] == 'c' && line[1] != 'y' )
	{
		scene->tracker.camera = 1;
		return (1);
	}
	else
		return (0);	
}

int		p_test_sphere(char *line)
{
	if((line[0] == 's' && line[1] == 'p' ))
		return (1);
	else
		return (0);	
}
int		p_test_plane(char *line)
{
	if((line[0] == 'p' && line[1] == 'l' ))
		return (1);
	else
		return (0);	
}
int		p_test_square(char *line)
{
	if((line[0] == 's' && line[1] == 'q' ))
		return (1);
	else
		return (0);	
}
int		p_test_cylinder(char *line)
{
	if((line[0] == 'c' && line[1] == 'y' ))
		return (1);
	else
		return (0);	
}
int		p_test_triangle(char *line)
{
	if((line[0] == 't' && line[1] == 'r' ))
		return (1);
	else
		return (0);	
}

int		p_test_point_light(char *line)
{
	if(line[0] == 'l')
	{
		return (1);
	}
	else
		return (0);	
}

int		p_test_ambient_light(t_scene *scene, char *line)
{
	if(line[0] == 'A')
	{	
		if(scene->tracker.ambient_light)
		{	
			exit(0); // Ambient light assigned more than once
		}
		else
		{
			scene->tracker.ambient_light = 1;
			return (1);
		}
	}
	else
		return (0);	
}

void	main_parser(t_rt *rt, char *line, int n)
{
	if(p_test_window(rt->scene, line))
		window_parsing(rt->scene, line, n);
	else if(p_test_sphere(line))
		sphere_parsing(rt->scene, line, n);
	else if(p_test_square(line))
		square_parsing(rt->scene, line, n);
	else if(p_test_cylinder(line))
		cylinder_parsing(rt->scene, line, n);	
	else if(p_test_triangle(line))
		triangle_parsing(rt->scene, line, n);
	else if(p_test_plane(line))
		plane_parsing(rt->scene, line, n);
	else if(p_test_point_light(line))
		point_light_parsing(&rt->scene->lights, line, n);
	else if(p_test_ambient_light(rt->scene, line))
		ambient_light_parsing(rt->scene, line, n);
	else if(p_test_camera(rt->scene, line))
		camera_parsing(&rt->scene->cameras, line, n);
	else if(!(string_empty(line)))
		parsing_err(rt, "Key not assigned", n);
}

void	scene_parsing(t_rt *rt)
{
	int retour;
	char *line;
	int	n;

	n = 0;
	init_parsing_tracker(rt->scene);
	// check if gnl problem
	while((retour = get_next_line(rt->scene->fd, &line)) > 0)
	{
		main_parser(rt->scene, line, n);
		free(line);
		n++;
	}
	if(retour == -1)
		arsing_err(rt, "Incorrect file format", n);;
	main_parser(rt->scene, line, n);
	free(line);
	close(rt->scene->fd);
	if(!(check_parsing_tracker(rt->scene)))
		parsing_err(rt, "Missing Resolution, Camera or Ambient light", -1);
	loopcameras(&rt->scene->cameras);
	rt->scene->active_camera = rt->scene->cameras->camera;
}
