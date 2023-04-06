/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:55:18 by jenavarr          #+#    #+#             */
/*   Updated: 2023/04/06 20:53:00 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/fdf.h"

void	connect_points(t_system *sys)
{
	int	i;
	int	ll;

	i = -1;
	ll = sys->map.ll;
	while (++i < sys->map.length)
	{
		if (i + ll < sys->map.length)
			draw_line(sys, sys->map.points[i], sys->map.points[i + ll]);
		if ((i + 1) % ll != 0)
			draw_line(sys, sys->map.points[i], sys->map.points[i + 1]);
	}
}

void	render(t_system *sys)
{
	init_view(sys);
	isometric(sys);
	debug_points(sys);
	//connect_points(sys);
	mlx_put_image_to_window(sys->mlx_ptr, sys->mlx_win, sys->img->img, 1920, 1080);
}
