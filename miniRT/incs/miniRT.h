/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celestin <celestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:25:48 by cmeunier          #+#    #+#             */
/*   Updated: 2020/02/28 17:22:46 by celestin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT_H
# define MINI_RT_H

// Standard libraries
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

// MinilibX
# include <mlx.h>

#define WINDOW_WIDTH	800
#define WINDOW_HEIGHT 	600
#define VIEWPORT_D		1
#define FOV				60

// Self-made headers
# include "RT_mlx.h"
# include "RT_lights.h"
# include "RT_scene.h"
# include "RT_colors.h"
# include "RT_maths.h"
# include "RT_utils.h"
# include "error.h"
# include "get_next_line.h"
# include "RT_parsing.h"
# include "RT_raytracing.h"

#endif