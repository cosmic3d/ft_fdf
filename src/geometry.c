/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 20:50:57 by jenavarr          #+#    #+#             */
/*   Updated: 2023/06/29 19:16:35 by jenavarr         ###   ########.fr       */
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
	int			i;
	t_matrix	rxyz;

	i = -1;
	sys->map.center = get_map_center(sys);
	rxyz = get_rxyz(sys);
	while (++i < sys->map.length)
	{
		sys->map.points[i].scopypos[X] -= sys->map.center.spos[X];
		sys->map.points[i].scopypos[Y] -= sys->map.center.spos[Y];
		rotate_point(&sys->map.points[i], rxyz);
		sys->map.points[i].scopypos[X] += sys->map.center.spos[X];
		sys->map.points[i].scopypos[Y] += sys->map.center.spos[Y];
		sys->map.points[i].spos[X] += sys->map.center.spos[X];
		sys->map.points[i].spos[Y] += sys->map.center.spos[Y];
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
		p[Z] *= mult;
		p[X] -= mousediff[X];
		p[Y] -= mousediff[Y];
		return ;
	}
	mult *= -1;
	p[X] /= mult;
	p[Y] /= mult;
	p[Z] /= mult;
	p[X] -= mousediff[X];
	p[Y] -= mousediff[Y];
}

void	zscale(t_system *sys, float change)
{
	int	i;

	i = -1;
	sys->view.z_scale += change;
	while (++i < sys->map.length)
	{
		sys->map.points[i].spos[Z] = (int)round(sys->map.points[i].pos[Z] \
		* sys->view.z_scale);
		sys->map.points[i].scopypos[Z] = sys->map.points[i].spos[Z];
	}
	angle(sys, sys->view.angle[X], sys->view.angle[Y], sys->view.angle[Z]);
	sys->map.change = 1;
}
