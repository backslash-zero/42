/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:25:48 by cmeunier          #+#    #+#             */
/*   Updated: 2020/01/25 18:19:43 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT_H
# define MINI_RT_H

# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

// MinilibX
# include <mlx.h>

#define	CAMERA_X		0
#define	CAMERA_Y		0
#define	CAMERA_Z		0

#define VIEWPORT_WIDTH	1
#define VIEWPORT_HEIGHT 1

#define VIEWPORT_D		1

#define WINDOW_WIDTH	800
#define WINDOW_HEIGHT 	800


// Personal Headers
# include "RT_parsing.h"
# include "error.h"
# include "get_next_line.h"
# include "utils.h"
# include "scene.h"

#endif