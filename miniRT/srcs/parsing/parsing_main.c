/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 17:57:51 by cmeunier          #+#    #+#             */
/*   Updated: 2020/03/11 12:02:22 by cmeunier         ###   ########.fr       */
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

void	main_parser(t_scene *scene, char *line)
{
	//check if line empty
	if(p_test_window(scene, line))
		window_parsing(scene, line);
	else if(p_test_sphere(line))
		sphere_parsing(scene, line);
	else if(p_test_square(line))
		square_parsing(scene, line);
	else if(p_test_cylinder(line))
		cylinder_parsing(scene, line);	
	else if(p_test_triangle(line))
		triangle_parsing(scene, line);
	else if(p_test_plane(line))
		plane_parsing(scene, line);
	else if(p_test_point_light(line))
		point_light_parsing(&scene->lights, line);
	else if(p_test_ambient_light(scene, line))
		ambient_light_parsing(scene, line);
	else if(p_test_camera(scene, line))
		camera_parsing(&scene->cameras, line);
	else if(!(string_empty(line)))
	{
		exit(0); // ELSE ERROR KEY ASSIGNED IS WRONG
	}
}

void	scene_parsing(t_scene *scene)
{
	int retour;
	char *line;
	int	i = 0;
	init_parsing_tracker(scene);
	// check if gnl problem
	while((retour = get_next_line(scene->fd, &line)) > 0)
	{
		printf("line: %d\n", ++i);
		main_parser(scene, line);
		free(line);
	}
	main_parser(scene, line);
	printf("parsed successfuly\n");
	free(line);
	close(scene->fd);
	if(!(check_parsing_tracker(scene)))
		exit(0); // Missing Resolution Camera or Ambient light elementfree all and exit
	loopcameras(&scene->cameras);
	printf("parsed successfuly\n");
	scene->active_camera = scene->cameras->camera;
}
