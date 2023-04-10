/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:19:06 by jenavarr          #+#    #+#             */
/*   Updated: 2023/04/10 19:46:04 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/fdf.h"

void	isometric(t_system *sys)
{
	float	x_iso;
	float	y_iso;
	t_point	iso_focus;
	int		i;

	i = -1;
	iso_focus.spos[X] = (int)(sys->dim.width - sys->dim.height) * \
	cos(deg_to_rad(sys->view.angle)) * sys->view.scale / 2;
	iso_focus.spos[Y] = (sys->dim.width + sys->dim.height) * \
	sin(deg_to_rad(sys->view.angle)) * sys->view.scale / 2;
	while (++i < sys->map.length)
	{
		x_iso = (sys->map.points[i].pos[X] - sys->map.points[i].pos[Y]) \
		* cos(deg_to_rad(sys->view.angle)) * \
		sys->view.scale + WINX / 2 - (int)iso_focus.spos[X];
		y_iso = (sys->map.points[i].pos[X] + sys->map.points[i].pos[Y]) \
		* sin(deg_to_rad(sys->view.angle)) * sys->view.scale - \
		sys->map.points[i].pos[Z] * \
		sys->view.z_scale + WINY / 2 - (int)iso_focus.spos[Y];
		sys->map.points[i].spos[X] = (int)round(x_iso);
		sys->map.points[i].spos[Y] = (int)round(y_iso);
	}
}
