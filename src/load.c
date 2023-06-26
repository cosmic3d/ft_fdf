/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:13:58 by jenavarr          #+#    #+#             */
/*   Updated: 2023/06/20 20:46:42 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/fdf.h"

void	load_map(t_system *sys, int fd)
{
	int		x;
	int		y;
	char	*line;
	char	**points;

	y = 0;
	sys->map.points = (t_point *)malloc(sizeof(t_point) * sys->map.length);
	sys->map.change = 0;
	line = get_next_line(fd);
	if (!sys->map.points || !line)
		f_exit("Malloc error when loading in the points");
	while (line)
	{
		x = -1;
		points = ft_split(line, ' ');
		if (!points)
			f_exit("Split error when loading in the points");
		while (points[++x])
			sys->map.points[x + (y * sys->map.ll)] = \
			load_xyz(points[x], x, y, sys->img->endian);
		ft_free(points);
		free(line);
		y++;
		line = get_next_line(fd);
	}
}

t_point	load_xyz(char *rawvals, int x, int y, int endian)
{
	t_point	point;
	char	**vals;

	point.color = 0xFFFFFF;
	if (ft_strrchr(rawvals, ',') && point.color != 0)
	{
		vals = ft_split(rawvals, ',');
		if (!vals)
			f_exit("Split error when loading a point");
		point.color = compose_color(hexstr_to_int(vals[1]), endian);
		ft_free(vals);
	}
	point.pos[Y] = y;
	point.pos[X] = x;
	point.pos[Z] = ft_atoi(rawvals);
	point.spos[X] = point.pos[X];
	point.spos[Y] = point.pos[Y];
	point.spos[Z] = point.pos[Z];
	return (point);
}

void	init_dims(t_system *sys)
{
	sys->dim.x.min = sys->map.points[0].pos[X];
	sys->dim.x.max = sys->map.points[0].pos[X];
	sys->dim.y.min = sys->map.points[0].pos[Y];
	sys->dim.y.max = sys->map.points[0].pos[Y];
	sys->dim.z.min = sys->map.points[0].pos[Z];
	sys->dim.z.max = sys->map.points[0].pos[Z];
}
