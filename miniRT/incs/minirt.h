/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:25:48 by cmeunier          #+#    #+#             */
/*   Updated: 2020/04/30 18:15:09 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>

# define MAX_WINDOW_WIDTH	2560
# define MAX_WINDOW_HEIGHT 	1440
# define WINDOW_WIDTH		400
# define WINDOW_HEIGHT 		300
# define VIEWPORT_D			1
# define FOV				60

# include "mlx.h"
# include "get_next_line.h"
# include "rt_maths.h"
# include "rt_scene.h"
# include "rt_mlx.h"
# include "rt_utils.h"
# include "rt_bmp.h"
# include "rt_colors.h"
# include "rt_error.h"
# include "rt_parsing.h"
# include "rt_raytracing.h"
# include "rt_lights.h"

#endif
