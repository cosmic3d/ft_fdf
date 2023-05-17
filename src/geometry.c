/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:47:09 by jenavarr          #+#    #+#             */
/*   Updated: 2023/05/17 15:53:37 by jenavarr         ###   ########.fr       */
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

void	scale(t_map *map, t_point multiplier)
{
	int	i;

	i = -1;
	while (++i < map->length)
	{
		map->points[i].pos[X] *= multiplier.pos[X];
		map->points[i].pos[Y] *= multiplier.pos[Y];
		map->points[i].pos[Z] *= multiplier.pos[Z];
	}
	map->change = 1;
}
