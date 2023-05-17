/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:13:52 by jenavarr          #+#    #+#             */
/*   Updated: 2023/05/17 20:30:57 by jenavarr         ###   ########.fr       */
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
}

double	*get_color_step(int one, int two, int p)
{
	double	*step_color;
	int		delta[4];

	delta[0] = (int)(two >> 24) - (int)(one >> 24);
	delta[1] = (int)((two >> 16) & 0xff) - (int)((one >> 16) & 0xff);
	delta[2] = (int)((two >> 8) & 0xff) - (int)((one >> 8) & 0xff);
	delta[3] = (int)(two & 0xff) - (int)(one & 0xff);

	// printf("Delta 0: %i\n", delta[0]);
	// printf("Delta 1: %i\n", delta[1]);
	// printf("Delta 2: %i\n", delta[2]);
	// printf("Delta 3: %i\n", delta[3]);
	step_color = malloc(4 * sizeof(double));
	step_color[0] = round(delta[0] / p);
	step_color[1] = round(delta[1] / p);
	step_color[2] = round(delta[2] / p);
	step_color[3] = round(delta[3] / p);
	// printf("Step 0: %i\n", step_color[0]);
	// printf("Step 1: %i\n", step_color[1]);
	// printf("Step 2: %i\n", step_color[2]);
	// printf("Step 3: %i\n", step_color[3]);

	return ((double *)step_color);
}
