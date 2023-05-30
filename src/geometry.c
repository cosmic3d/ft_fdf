/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:47:09 by jenavarr          #+#    #+#             */
/*   Updated: 2023/05/30 21:39:27 by jenavarr         ###   ########.fr       */
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

void	scale(t_map *map, float mult)
{
	int	i;

	i = -1;
	if (map->points[1].spos[X] - map->points[0].spos[X] < MAXZOOMOUT
		&& mult < 0)
		return ;
	if (map->points[1].spos[X] - map->points[0].spos[X] > MAXZOOMIN && mult > 0)
		return ;
	if (mult > 0)
	{
		while (++i < map->length)
		{
			map->points[i].spos[X] *= mult;
			map->points[i].spos[Y] *= mult;
		}
		printf("Distance is: %2f\n", map->points[1].spos[X]
				- map->points[0].spos[X]);
		map->change = 1;
		return ;
	}
	mult *= -1;
	while (++i < map->length)
	{
		map->points[i].spos[X] /= mult;
		map->points[i].spos[Y] /= mult;
	}
	printf("Distance is: %2f\n", map->points[1].spos[X]
			- map->points[0].spos[X]);
	map->change = 1;
	return ;
}
