/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:19:06 by jenavarr          #+#    #+#             */
/*   Updated: 2023/06/12 19:49:22 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/fdf.h"

void	isometric(t_system *sys)
{
	// t_point	iso_focus;
	// int		i;

	// i = -1;
	// iso_focus.spos[X] = (int)(sys->dim.width - sys->dim.height)
	// 	* cos(deg_to_rad(sys->view.angle)) * sys->view.scale / 2;
	// iso_focus.spos[Y] = (int)(sys->dim.width + sys->dim.height)
	// 	* sin(deg_to_rad(sys->view.angle)) * sys->view.scale / 2;
	// while (++i < sys->map.length)
	// {
		// x_iso = (sys->map.points[i].pos[X] - sys->map.points[i].pos[Y])
		// 	* cos(deg_to_rad(sys->view.angle)) * sys->view.scale + WINX / 2
		// 	- (int)iso_focus.spos[X];
		// y_iso = (sys->map.points[i].pos[X] + sys->map.points[i].pos[Y])
		// 	* sin(deg_to_rad(sys->view.angle)) * sys->view.scale
		// 	- sys->map.points[i].pos[Z] * sys-view.z_scale >+ WINY / 2
		// 	- (int)iso_focus.spos[Y];
		// sys->map.points[i].spos[X] = (int)round(x_iso);
		// sys->map.points[i].spos[Y] = (int)round(y_iso);
	// }
	int		i;
	float	x_iso;
	float	y_iso;

	i = -1;
	while (++i < sys->map.length)
	{
		x_iso = sys->map.points[i].pos[X] * sys->view.scale + WINX / 4;
		y_iso = sys->map.points[i].pos[Y] * sys->view.scale + WINY / 4;
		sys->map.points[i].spos[X] = (int)round(x_iso);
		sys->map.points[i].spos[Y] = (int)round(y_iso);
		sys->map.points[i].spos[Z] = (int)round(sys->map.points[i].pos[Z] \
		* sys->view.z_scale);
	}
	sys->map.change = 1;
}
