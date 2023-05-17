/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:55:18 by jenavarr          #+#    #+#             */
/*   Updated: 2023/05/17 20:37:17 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/fdf.h"

double	*current_step(double *step, int p)
{
	int	i;

	i = -1;
	while (++i < 4)
		step[i] *= p;
	return ((double *)step);
}

int	next_color(int *origin, double *step)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		origin[i] += step[i];
		origin[i] = (int)round(origin[i]);
	}
	return (*(int *)origin);
}

void	draw_line(t_system *sys, t_point one, t_point two, double *step)
{
	double			delta[2];
	double			xy[2];
	double			*progress;
	int				pixels[2];

	delta[X] = (double)two.spos[X] - (double)one.spos[X];
	delta[Y] = (double)two.spos[Y] - (double)one.spos[Y];
	if (!delta[X] && !delta[Y])
		return ;
	pixels[0] = (int)sqrt((delta[X] * delta[X]) + (delta[Y] * delta[Y]));
	delta[X] /= pixels[0];
	delta[Y] /= pixels[0];
	xy[X] = one.spos[X];
	xy[Y] = one.spos[Y];
	step = get_color_step(one.color, two.color, pixels[0]);
	pixels[1] = 0;
	while (pixels[0])
	{
		printf("Pos x: %i\n", (int)round(xy[X]));
		printf("Pos y: %i\n", (int)round(xy[Y]));
		printf("Delta x: %f\n", delta[X]);
		printf("Delta y: %f\n", delta[Y]);
		put_pixel(sys->img, (int)round(xy[X]), (int)round(xy[Y]), one.color);
		xy[X] += delta[X];
		xy[Y] += delta[Y];
		progress = current_step(step, ++pixels[1]);
		printf("Progress 0 is: %F\n", progress[0]);
		printf("Progress 1 is: %F\n", progress[1]);
		printf("Progress 2 is: %F\n", progress[2]);
		printf("Progress 3 is: %F\n", progress[3]);
		one.color = next_color(&one.color, progress);
		pixels[0]--;
	}
	free(step);
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
	sys->map.change = 0;
}
