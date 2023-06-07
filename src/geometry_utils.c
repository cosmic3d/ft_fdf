/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 19:25:19 by jenavarr          #+#    #+#             */
/*   Updated: 2023/06/07 19:16:19 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/fdf.h"

void	get_lowest_distance(t_map *map)
{
	int	i;
	int	distances[2];

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

int	get_distance(t_point one, t_point two)
{
	int	delta[2];

	delta[X] = two.spos[X] - one.spos[X];
	delta[Y] = two.spos[Y] - one.spos[Y];
	return (sqrt((delta[X] * delta[X]) + (delta[Y] * delta[Y])));
}

int	point_inside_screen(t_point one, t_point two)
{
	if (one.spos[X] < WINX && one.spos[X] > 0 && one.spos[Y] < WINY
		&& one.spos[Y] > 0)
		return (1);
	if (two.spos[X] < WINX && two.spos[X] > 0 && two.spos[Y] < WINY
		&& two.spos[Y] > 0)
		return (1);
	return (0);
}
