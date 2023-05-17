/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 18:19:48 by jenavarr          #+#    #+#             */
/*   Updated: 2023/05/17 15:54:03 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/fdf.h"

void	hook(t_system *sys)
{
	mlx_hook(sys->mlx_win, 17, 0, f_exit, "");
	mlx_hook(sys->mlx_win, 2, 0, keypressed, sys);
}

int	keypressed(int keycode, t_system *sys)
{
	if (keycode == KEY_ESC)
		f_exit("");
	if (keycode == KEY_LEFT)
		translate(&sys->map, -TRANSLATE, 0);
	if (keycode == KEY_RIGHT)
		translate(&sys->map, TRANSLATE, 0);
	if (keycode == KEY_UP)
		translate(&sys->map, 0, -TRANSLATE);
	if (keycode == KEY_DOWN)
		translate(&sys->map, 0, TRANSLATE);
	if (keycode == KEY_I)
		isometric(sys);
	if (sys->map.change)
		render(sys);
	return (0);
}
