/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:55:18 by jenavarr          #+#    #+#             */
/*   Updated: 2023/06/13 19:36:24 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/fdf.h"

void	next_color(int *origin, double *step)
{
	unsigned char	*bytes;

	bytes = (unsigned char *)origin;
	bytes[0] += (int)round(step[3]);
	bytes[1] += (int)round(step[2]);
	bytes[2] += (int)round(step[1]);
	bytes[3] += (int)round(step[0]);
}

void	draw_line(t_system *sys, t_point one, t_point two, double *s)
{
	double	delta[2];
	double	xy[2];
	int		pixels;

	delta[X] = two.spos[X] - one.spos[X];
	delta[Y] = two.spos[Y] - one.spos[Y];
	if (!delta[X] && !delta[Y])
		return ;
	pixels = sqrt((delta[X] * delta[X]) + (delta[Y] * delta[Y]));
	if (!pixels)
		return ;
	delta[X] /= pixels;
	delta[Y] /= pixels;
	xy[X] = one.spos[X];
	xy[Y] = one.spos[Y];
	s = get_color_step(one.color, two.color, pixels);
	while (pixels)
	{
		put_pixel(sys->img, (int)round(xy[X]), (int)round(xy[Y]), one.color);
		xy[X] += delta[X];
		xy[Y] += delta[Y];
		next_color(&one.color, s);
		pixels--;
	}
	free(s);
}

void	connect_points(t_system *sys)
{
	int	i;
	int	ll;

	i = -1;
	ll = sys->map.ll;
	while (++i < sys->map.length)
	{
		if (i + ll < sys->map.length)
			if (cohensutherland(sys->map.points[i], \
			sys->map.points[i + ll]))
				draw_line(sys, sys->map.points[i], \
				sys->map.points[i + ll], 0x0);
		if (((i + 1) % ll != 0))
			if (cohensutherland(sys->map.points[i], \
			sys->map.points[i + 1]))
				draw_line(sys, sys->map.points[i], \
				sys->map.points[i + 1], 0x0);
	}
}

void	render(t_system *sys)
{
	clean_img(sys);
	connect_points(sys);
	mlx_put_image_to_window(sys->mlx_ptr, sys->mlx_win, sys->img->img, 0, 0);
	sys->map.change = 0;
}
