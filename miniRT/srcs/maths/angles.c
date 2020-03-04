/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 13:26:50 by cmeunier          #+#    #+#             */
/*   Updated: 2020/03/04 13:27:06 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

double	rot_to_deg(double rotation)
{
	return(rotation * 180);
}

double	rad(double nb)
{
	nb = nb * M_PI / 180;
	return (nb);
}
