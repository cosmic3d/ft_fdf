/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 18:19:48 by jenavarr          #+#    #+#             */
/*   Updated: 2023/06/29 19:24:06 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/fdf.h"

void	hook(t_system *sys)
{
	mlx_hook(sys->mlx_win, DESTROY_NOTIFY, 0, f_exit, "");
	mlx_hook(sys->mlx_win, KEY_PRESS, 0, keypressed, sys);
	mlx_hook(sys->mlx_win, BUTTON_MOUSEDOWN, 0, mousedown, sys);
	mlx_hook(sys->mlx_win, BUTTON_MOUSEMOVE, 0, mousemove, sys);
	mlx_hook(sys->mlx_win, BUTTON_MOUSEUP, 0, mouseup, sys);
}

int	keypressed(int keycode, t_system *sys)
{
	keypressed_2(keycode, sys);
	if (keycode == KEY_Q)
		angle(sys, sys->view.angle[X], \
		sys->view.angle[Y], sys->view.angle[Z] - 1);
	if (keycode == KEY_E)
		angle(sys, sys->view.angle[X], \
		sys->view.angle[Y], sys->view.angle[Z] + 1);
	if (keycode == KEY_Z)
		zscale(sys, ZFACTOR_MOD);
	if (keycode == KEY_X)
		zscale(sys, -ZFACTOR_MOD);
	if (keycode == KEY_ESC)
		f_exit("");
	if (keycode == KEY_I)
		isometric(sys);
	if (keycode == KEY_P)
		parallel(sys);
	if (sys->map.change)
		render(sys);
	return (0);
}

void	keypressed_2(int keycode, t_system *sys)
{
	if (keycode == KEY_LEFT)
		translate(&sys->map, -TRANSLATE, 0);
	if (keycode == KEY_RIGHT)
		translate(&sys->map, TRANSLATE, 0);
	if (keycode == KEY_UP)
		translate(&sys->map, 0, -TRANSLATE);
	if (keycode == KEY_DOWN)
		translate(&sys->map, 0, TRANSLATE);
	if (keycode == KEY_W)
		angle(sys, sys->view.angle[X] + 1, \
		sys->view.angle[Y], sys->view.angle[Z]);
	if (keycode == KEY_A)
		angle(sys, sys->view.angle[X], \
		sys->view.angle[Y] - 1, sys->view.angle[Z]);
	if (keycode == KEY_S)
		angle(sys, sys->view.angle[X] - 1, \
		sys->view.angle[Y], sys->view.angle[Z]);
	if (keycode == KEY_D)
		angle(sys, sys->view.angle[X], \
		sys->view.angle[Y] + 1, sys->view.angle[Z]);
}
