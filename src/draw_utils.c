/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:13:52 by jenavarr          #+#    #+#             */
/*   Updated: 2023/04/23 19:53:03 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/fdf.h"

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

void	clean_img(t_system *sys)
{
	int	i;
	int	j;

	i = -1;
	while (++i < WINY)
	{
		j = -1;
		while (++j < WINX)
			put_pixel(sys->img, j, i, 0x0);
	}
}

void	init_view(t_system *sys)
{
	get_max_dims(sys);
	sys->view.angle = 35.26;
	sys->view.window_occ = 0.5;
	sys->view.scale = get_scale_factor(sys);
	sys->view.z_scale = (WINX * WINY) / (sys->dim.width * sys->dim.height * \
	pow(sys->view.scale, 2) * log(sys->dim.altitude + 2));
	isometric(sys);
	// printf("View scale is: %f", sys->view.scale);
	// printf("View z scale is: %f", sys->view.z_scale);
	// f_exit("uwu");
}

unsigned int	get_color_step(unsigned int one, unsigned int two, int p)
{
	unsigned int	step_color[4];

	step_color[0] = ((int)(two >> 24) - (int)(one >> 24)) / p;
	step_color[1] = ((int)((two >> 16) & 0xff) - (int)((one >> 16) & 0xff)) / p;
	step_color[2] = ((int)((two >> 8) & 0xff) - (int)((one >> 8) & 0xff)) / p;
	step_color[3] = ((int)(two & 0xff) - (int)(one & 0xff)) / p;
	return (*(unsigned int *)step_color);
}
