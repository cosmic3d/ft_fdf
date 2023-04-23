/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:55:18 by jenavarr          #+#    #+#             */
/*   Updated: 2023/04/23 20:04:41 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/fdf.h"

void	draw_line(t_system *sys, t_point one, t_point two, unsigned int step)
{
	double			delta_x;
	double			delta_y;
	double			pixel_x;
	double			pixel_y;
	int				pixels;

	delta_x = (double)two.spos[X] - (double)one.spos[X];
	delta_y = (double)two.spos[Y] - (double)one.spos[Y];
	pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	delta_x /= pixels;
	delta_y /= pixels;
	pixel_x = one.spos[X];
	pixel_y = one.spos[Y];
	step = get_color_step(one.color, two.color, pixels);
	while (pixels)
	{
		put_pixel(sys->img, (int)pixel_x, (int)pixel_y, one.color);
		pixel_x += delta_x;
		pixel_y += delta_y;
		one.color += step;
		pixels--;
	}
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
			draw_line(sys, sys->map.points[i], sys->map.points[i + ll], 0x0);
		if ((i + 1) % ll != 0)
			draw_line(sys, sys->map.points[i], sys->map.points[i + 1], 0x0);
	}
}

void	render(t_system *sys)
{
	clean_img(sys);
	connect_points(sys);
	mlx_put_image_to_window(sys->mlx_ptr, sys->mlx_win, sys->img->img, 0, 0);
}
