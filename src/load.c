/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:13:58 by jenavarr          #+#    #+#             */
/*   Updated: 2023/04/04 17:13:17 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/fdf.h"

void	load_map(t_system *sys, int fd)
{
	int		x;
	int		z;
	char	*line;
	char	**points;

	z = 0;
	sys->map.points = (t_point *)malloc(sizeof(t_point) * sys->map.length);
	line = get_next_line(fd);
	if (!sys->map.points || !line)
		f_exit("Malloc error when loading in the points");
	while (line)
	{
		x = -1;
		points = ft_split(line, ' ');
		free(line);
		if (!points)
			f_exit("Split error when loading in the points");
		while (points[++x])
			sys->map.points[x + (z * sys->map.ll)] = \
			load_xyz(points[x], x, z, sys->img->endian);
		ft_free(points);
		z++;
		line = get_next_line(fd);
	}
}

t_point	load_xyz(char *rawvals, int x, int z, int endian)
{
	t_point	point;
	char	**vals;

	if (ft_strrchr(rawvals, ','))
	{
		vals = ft_split(rawvals, ',');
		if (!vals)
			f_exit("Split error when loading a point");
		point.color = compose_color(hexstr_to_int(vals[1]), endian);
	}
	point.pos[Y] = ft_atoi(rawvals);
	point.pos[X] = x;
	point.pos[Z] = z;
	return (point);
}
