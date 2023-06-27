/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 19:25:19 by jenavarr          #+#    #+#             */
/*   Updated: 2023/06/27 21:33:18 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/fdf.h"

void	get_lowest_distance(t_map *map)
{
	int		i;
	float	distances[2];

	i = -1;
	map->zoom = 0;
	while (++i < map->length)
	{
		if ((i + 1) % map->ll != 0)
		{
			distances[0] = get_distance(map->points[i], map->points[i + 1]);
			map->zoom = distances[0];
		}
		if (i + map->ll < map->length)
		{
			distances[1] = get_distance(map->points[i], map->points[i
					+ map->ll]);
			if (map->zoom == 0)
				map->zoom = distances[1];
			if (map->zoom != 0 && distances[0] > distances[1])
				map->zoom = distances[1];
		}
	}
}

float	get_distance(t_point one, t_point two)
{
	float	delta[2];

	delta[X] = two.spos[X] - one.spos[X];
	delta[Y] = two.spos[Y] - one.spos[Y];
	return (sqrt((delta[X] * delta[X]) + (delta[Y] * delta[Y])));
}

t_point	get_map_center(t_system *sys)
{
	t_point	center;

	center.spos[X] = (sys->map.points[sys->map.length - 1].scopypos[X] \
	- sys->map.points[0].scopypos[X]) / 2 + sys->map.points[0].scopypos[X];
	center.spos[Y] = (sys->map.points[sys->map.length - 1].scopypos[Y] \
	- sys->map.points[0].scopypos[Y]) / 2 + sys->map.points[0].scopypos[Y];
	return (center);
}

void	change_angle_with_mouse(t_system *sys, int x, int y)
{
	int	x_diff;
	int	y_diff;

	x_diff = sys->hooks.leftclickdownpos[X] - x;
	y_diff = sys->hooks.leftclickdownpos[Y] - y;
	sys->view.angle[X] = sys->hooks.leftclickdownangle[X] \
	+ y_diff / ROTATE_DIV;
	sys->view.angle[Y] = sys->hooks.leftclickdownangle[Y] \
	- x_diff / ROTATE_DIV;
	clamp_angle(sys);
}

void	clamp_angle(t_system *sys)
{
	if (sys->view.angle[X] >= 360)
		sys->view.angle[X] -= 360;
	if (sys->view.angle[X] < 0)
		sys->view.angle[X] += 360;
	if (sys->view.angle[Y] >= 360)
		sys->view.angle[Y] -= 360;
	if (sys->view.angle[Y] < 0)
		sys->view.angle[Y] += 360;
	if (sys->view.angle[Z] >= 360)
		sys->view.angle[Z] -= 360;
	if (sys->view.angle[Z] < 0)
		sys->view.angle[Z] += 360;
}
