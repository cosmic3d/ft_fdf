/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:13:52 by jenavarr          #+#    #+#             */
/*   Updated: 2023/04/10 18:09:25 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/fdf.h"

void	draw_line(t_system *sys, t_point one, t_point two)
{
	double	delta_x;
	double	delta_y;
	double	pixel_x;
	double	pixel_y;
	int		pixels;

	delta_x = (double)two.spos[X] - (double)one.spos[X];
	delta_y = (double)two.spos[Y] - (double)one.spos[Y];
	pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	delta_x /= pixels;
	delta_y /= pixels;
	pixel_x = one.spos[X];
	pixel_y = one.spos[Y];
	while (pixels)
	{
		put_pixel(sys->img, (int)pixel_x, (int)pixel_y, 0xFFFFFF);
		pixel_x += delta_x;
		pixel_y += delta_y;
		pixels--;
	}
}

void	get_max_dims(t_system *sys)
{
	int	i;

	i = -1;
	init_dims(sys);
	while (++i < sys->map.length)
	{
		if (sys->map.points[i].pos[X] < sys->dim.x.min)
			sys->dim.x.min = sys->map.points[i].pos[X];
		if (sys->map.points[i].pos[X] > sys->dim.x.max)
			sys->dim.x.max = sys->map.points[i].pos[X];
		if (sys->map.points[i].pos[Y] < sys->dim.y.min)
			sys->dim.y.min = sys->map.points[i].pos[Y];
		if (sys->map.points[i].pos[Y] > sys->dim.y.max)
			sys->dim.y.max = sys->map.points[i].pos[Y];
		if (sys->map.points[i].pos[Z] < sys->dim.z.min)
			sys->dim.z.min = sys->map.points[i].pos[Z];
		if (sys->map.points[i].pos[Z] > sys->dim.z.max)
			sys->dim.z.max = sys->map.points[i].pos[Z];
	}
	sys->dim.width = get_abs(sys->dim.x.max - sys->dim.x.min);
	sys->dim.height = get_abs(sys->dim.y.max - sys->dim.y.min);
	sys->dim.altitude = get_abs(sys->dim.z.max - sys->dim.z.min);
}

float	get_scale_factor(t_system *sys)
{
	float	scale_x;
	float	scale_y;

	scale_x = sys->dim.width / (float)WINX;
	scale_y = sys->dim.height / (float)WINY;
	if (scale_x > scale_y)
		return (sys->view.window_occ / scale_x);
	return (sys->view.window_occ / scale_y);
}

void	init_view(t_system *sys)
{
	get_max_dims(sys);
	sys->view.angle = 35.26;
	sys->view.window_occ = 0.5;
	sys->view.scale = get_scale_factor(sys);
	sys->view.z_scale = (WINX * WINY) / (sys->dim.width * sys->dim.height * \
	pow(sys->view.scale, 2) * log(sys->dim.altitude + 2));
	// printf("View scale is: %f", sys->view.scale);
	// printf("View z scale is: %f", sys->view.z_scale);
	// f_exit("uwu");
}
