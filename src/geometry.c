/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:47:09 by jenavarr          #+#    #+#             */
/*   Updated: 2023/06/13 21:15:28 by jenavarr         ###   ########.fr       */
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
		map->points[i].scopypos[X] += x;
		map->points[i].scopypos[Y] += y;
	}
	map->change = 1;
}

void	rotate(t_system *sys)
{
	int	i;

	i = -1;
	while (++i < sys->map.length)
	{
		rot_x(sys, &sys->map.points[i]);
		rot_y(sys, &sys->map.points[i]);
		rot_z(sys, &sys->map.points[i]);
	}
	sys->map.change = 1;
}

void	scale(t_map *map, float mult, int mousex, int mousey)
{
	int	mousediff[2];
	int	i;

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
	i = -1;
	while (++i < map->length)
	{
		zoom(map->points[i].spos, mult, mousediff);
		zoom(map->points[i].scopypos, mult, mousediff);
	}
	map->change = 1;
	get_lowest_distance(map);
	return ;
}

void	zoom(float *p, float mult, int mousediff[2])
{
	if (mult > 0)
	{
		p[X] *= mult;
		p[Y] *= mult;
		p[X] -= mousediff[X];
		p[Y] -= mousediff[Y];
		return ;
	}
	mult *= -1;
	p[X] /= mult;
	p[Y] /= mult;
	p[X] -= mousediff[X];
	p[Y] -= mousediff[Y];
}
