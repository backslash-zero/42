/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 17:57:51 by cmeunier          #+#    #+#             */
/*   Updated: 2020/03/12 18:10:23 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minirt.h"

void	main_parser(t_rt *rt, char *line, int n)
{
	if (p_test_window(rt, line, n))
		window_parsing(rt, line, n);
	else if (p_test_sphere(line))
		sphere_parsing(rt, line, n);
	else if (p_test_square(line))
		square_parsing(rt, line, n);
	else if (p_test_cylinder(line))
		cylinder_parsing(rt, line, n, 2);
	else if (p_test_triangle(line))
		triangle_parsing(rt, line, n);
	else if (p_test_plane(line))
		plane_parsing(rt, line, n);
	else if (p_test_point_light(line))
		point_light_parsing(rt, line, n);
	else if (p_test_ambient_light(rt, line, n))
		ambient_light_parsing(rt, line, n);
	else if (p_test_camera(rt->scene, line))
		camera_parsing(rt, line, n);
	else if (!(string_empty(line)))
		parsing_err(rt, "Key not assigned", n);
}

void	scene_parsing(t_rt *rt)
{
	int		retour;
	char	*line;
	int		n;

	n = 0;
	init_parsing_tracker(rt->scene);
	while ((retour = get_next_line(rt->scene->fd, &line)) > 0)
	{
		main_parser(rt, line, n);
		free(line);
		n++;
	}
	if (retour == -1)
		parsing_err(rt, "Incorrect file format", n);
	main_parser(rt, line, n);
	free(line);
	close(rt->scene->fd);
	if (!(check_parsing_tracker(rt->scene)))
		parsing_err(rt, "Missing Resolution, Camera or Ambient light", -1);
	loopcameras(&rt->scene->cameras);
	rt->scene->active_camera = rt->scene->cameras->camera;
}
