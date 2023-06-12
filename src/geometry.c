/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:47:09 by jenavarr          #+#    #+#             */
/*   Updated: 2023/06/12 21:22:10 by jenavarr         ###   ########.fr       */
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

void	rotate(t_system *sys, int x, int y)
{
	int	i;

	i = -1;
	change_angle(sys, x, y);
	printf("Y before: %f\n", sys->map.points[0].spos[Y]);
	while (++i < sys->map.length)
	{
		sys->map.points[i].spos[Y] = sys->map.points[i].spos[Y] * cos(sys->view.angle[X]) - sys->map.points[i].spos[Z] * sin(sys->view.angle[X]);
	}
	printf("Y after: %f\n", sys->map.points[0].spos[Y]);
	printf("X angle is: %i\n\n", sys->view.angle[X]);
	sys->map.change = 1;
}

void	scale(t_map *map, float mult, int mousex, int mousey)
{
	int	mousediff[2];

	if ((mult < 0 && map->zoom <= MAXZOOMOUT) || \
	(mult > 0 && map->zoom >= MAXZOOMIN))
		return ;
	if (mult > 0)
	{
		mousediff[X] = (mousex * mult) - mousex;
		mousediff[Y] = (mousey * mult) - mousey;
	}
	else
	{
		mousediff[X] = (mousex / get_abs(mult)) - mousex;
		mousediff[Y] = (mousey / get_abs(mult)) - mousey;
	}
	zoom(map, mult, mousediff);
	map->change = 1;
	get_lowest_distance(map);
	return ;
}

void	zoom(t_map *map, float mult, int mousediff[2])
{
	int	i;

	i = -1;
	if (mult > 0)
	{
		while (++i < map->length)
		{
			map->points[i].spos[X] *= mult;
			map->points[i].spos[Y] *= mult;
			map->points[i].spos[X] -= mousediff[X];
			map->points[i].spos[Y] -= mousediff[Y];
		}
		return ;
	}
	else
	{
		mult *= -1;
		while (++i < map->length)
		{
			map->points[i].spos[X] /= mult;
			map->points[i].spos[Y] /= mult;
			map->points[i].spos[X] -= mousediff[X];
			map->points[i].spos[Y] -= mousediff[Y];
		}
	}
}
