/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:19:06 by jenavarr          #+#    #+#             */
/*   Updated: 2023/06/13 18:53:13 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/fdf.h"

void	isometric(t_system *sys)
{
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
		sys->map.points[i].scopypos[X] = sys->map.points[i].spos[X];
		sys->map.points[i].scopypos[Y] = sys->map.points[i].spos[Y];
		sys->map.points[i].scopypos[Z] = sys->map.points[i].spos[Z];
	}
	sys->map.change = 1;
}
