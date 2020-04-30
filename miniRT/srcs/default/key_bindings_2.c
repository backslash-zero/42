/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_bindings_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 15:38:32 by cmeunier          #+#    #+#             */
/*   Updated: 2020/04/30 19:34:43 by cmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minirt.h"

int		ft_key_exit(int key, t_rt *rt)
{
	if (key == 65307)
		exit_success(rt);
	return (0);
}

int		ft_key_switch(int key, t_rt *rt)
{
	if (key == 99)
	{
		rt->scene->cameras = rt->scene->cameras->next;
		rt->scene->active_camera = rt->scene->cameras->camera;
		display_image(rt);
		return (0);
	}
	else
		return (0);
}
