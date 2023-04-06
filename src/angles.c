/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:19:06 by jenavarr          #+#    #+#             */
/*   Updated: 2023/04/06 21:13:30 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/fdf.h"

void	isometric(t_system *sys)
{
	float	x_iso;
	float	y_iso;
	int		i;

	i = -1;
	while (++i < sys->map.length)
	{
		x_iso = (sys->map.points[i].pos[X] - sys->map.points[i].pos[Y]) \
		* cos(deg_to_rad(sys->view.angle)) * sys->view.scale + WINX / 2;
		y_iso = (sys->map.points[i].pos[X] + sys->map.points[i].pos[Y]) \
		* sin(deg_to_rad(sys->view.angle)) * sys->view.scale - \
		sys->map.points[i].pos[Z] * sys->view.z_scale + WINX / 2;
		sys->map.points[i].spos[X] = x_iso;
		sys->map.points[i].spos[Y] = y_iso;
		printf("Going %i\n", i);
	}
}
