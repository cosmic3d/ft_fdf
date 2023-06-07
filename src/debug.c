/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:36:47 by jenavarr          #+#    #+#             */
/*   Updated: 2023/06/07 18:46:38 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/fdf.h"

void	debug_split(char **strings)
{
	ft_printf("\"%s\"\n", *strings);
	while (*strings)
	{
		strings++;
		ft_printf("\"%s\"\n", *strings);
	}
}

void	debug_points(t_system *sys)
{
	int	i;

	i = -1;
	while (++i < sys->map.length)
	{
		printf("--------------------\n");
		printf("Id: %i\n", i);
		printf("pos:\n");
		printf("\tX: %f\n", sys->map.points[i].pos[X]);
		printf("\tY: %f\n", sys->map.points[i].pos[Y]);
		printf("\tZ: %f\n", sys->map.points[i].pos[Z]);
		printf("Screen pos:\n");
		printf("\tX: %f\n", sys->map.points[i].spos[X]);
		printf("\tY: %f\n", sys->map.points[i].spos[Y]);
		printf("\tZ: %f\n", sys->map.points[i].spos[Z]);
	}
	printf("view scale = %f\n", sys->view.scale);
}

void	debug_line(t_system *sys)
{
	t_point	one;
	t_point	two;

	one.spos[0] = 960;
	one.spos[1] = 1120;
	one.spos[2] = 0;
	two.spos[0] = 1920;
	two.spos[1] = 1080;
	two.spos[2] = 0;
	draw_line(sys, one, two, 0x0);
	mlx_put_image_to_window(sys->mlx_ptr, sys->mlx_win, sys->img->img, 0, 0);
}

void	debug_colors(t_system *sys)
{
	int	i;

	i = -1;
	while (++i < sys->map.length)
		printf("Point %i color is: %x\n", i, sys->map.points[i].color);
}
