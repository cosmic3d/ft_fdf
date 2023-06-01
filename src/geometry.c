/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:47:09 by jenavarr          #+#    #+#             */
/*   Updated: 2023/06/01 21:38:42 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/fdf.h"

void	translate(t_map *map, int x, int y)
{
	int	i;

	i = -1;
	while (++i < map->length)
	{
		map->points[i].spos[X] += x;
		map->points[i].spos[Y] += y;
	}
	map->change = 1;
}

void	scale(t_map *map, float mult, int mousex, int mousey)
{
	int	i;

	i = -1;
	mousex = 0;
	mousey = 0;
	if (mult < 0 && map->zoom <= 1)
		return ;
	if (mult > 0)
	{
		while (++i < map->length)
		{
			map->points[i].spos[X] *= mult;
			map->points[i].spos[Y] *= mult;
			// map->points[i].spos[X] += mousex - map->points[i].spos[X];
			// map->points[i].spos[Y] += mousey - map->points[i].spos[Y];
		}
		map->change = 1;
		get_lowest_distance(map);
		return ;
	}
	mult *= -1;
	while (++i < map->length)
	{
		map->points[i].spos[X] /= mult;
		map->points[i].spos[Y] /= mult;
		// map->points[i].spos[X] += mousex - map->points[i].spos[X];
		// map->points[i].spos[Y] += mousey - map->points[i].spos[Y];
	}
	map->change = 1;
	get_lowest_distance(map);
	return ;
}
