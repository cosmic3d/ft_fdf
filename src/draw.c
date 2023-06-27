/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:55:18 by jenavarr          #+#    #+#             */
/*   Updated: 2023/06/27 21:18:19 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/fdf.h"

void	next_color(int *origin, int *color_tmp, int p, double *step)
{
	unsigned char	*bytes;
	unsigned char	*tmp_init;

	bytes = (unsigned char *)origin;
	tmp_init = (unsigned char *)color_tmp;
	bytes[0] = (int)round(tmp_init[0] + (step[3] * p));
	bytes[1] = (int)round(tmp_init[1] + (step[2] * p));
	bytes[2] = (int)round(tmp_init[2] + (step[1] * p));
	bytes[3] = (int)round(tmp_init[3] + (step[0] * p));
}

void	draw_line(t_system *sys, t_point one, t_point two, double *s)
{
	double	delta[2];
	double	xy[2];
	int		pixels;
	int		utils_tmp[2];

	delta[X] = two.spos[X] - one.spos[X];
	delta[Y] = two.spos[Y] - one.spos[Y];
	pixels = sqrt((delta[X] * delta[X]) + (delta[Y] * delta[Y]));
	if (!pixels)
		return ;
	delta[X] /= pixels;
	delta[Y] /= pixels;
	xy[X] = one.spos[X];
	xy[Y] = one.spos[Y];
	s = get_color_step(one.color, two.color, pixels);
	utils_tmp[0] = one.color;
	utils_tmp[1] = pixels;
	while (pixels--)
	{
		put_pixel(sys->img, (int)round(xy[X]), (int)round(xy[Y]), one.color);
		xy[X] += delta[X];
		xy[Y] += delta[Y];
		next_color(&one.color, &utils_tmp[0], utils_tmp[1] - pixels, s);
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
	print_info(sys);
	sys->map.change = 0;
}
