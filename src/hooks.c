/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 18:19:48 by jenavarr          #+#    #+#             */
/*   Updated: 2023/06/13 20:55:27 by jenavarr         ###   ########.fr       */
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

int	mousedown(int button, int x, int y, t_system *sys)
{
	if (button == MOUSE_LEFTCLICK)
	{
		sys->hooks.leftclickdownangle[X] = sys->view.angle[X];
		sys->hooks.leftclickdownangle[Y] = sys->view.angle[Y];
		sys->hooks.leftclickdownpos[X] = x;
		sys->hooks.leftclickdownpos[Y] = y;
		sys->hooks.isleftclickdown = 1;
	}
	if (button == MOUSE_RIGHTCLICK)
	{
		sys->hooks.rightclickdownpos[X] = x;
		sys->hooks.rightclickdownpos[Y] = y;
		sys->hooks.isrightclickdown = 1;
	}
	if (button == MOUSE_SCROLLDOWN)
		scale(&sys->map, ZOOM, x, y);
	if (button == MOUSE_SCROLLUP)
		scale(&sys->map, -ZOOM, x, y);
	if (sys->map.change)
		render(sys);
	return (0);
}

int	mouseup(int button, int x, int y, t_system *sys)
{
	if (button == MOUSE_LEFTCLICK)
	{
		sys->hooks.isleftclickdown = 0;
		sys->hooks.leftclickdownangle[X] = sys->view.angle[X];
		sys->hooks.leftclickdownangle[Y] = sys->view.angle[Y];
		sys->hooks.leftclickdownpos[X] = x;
		sys->hooks.leftclickdownpos[Y] = y;
	}
	if (button == MOUSE_RIGHTCLICK)
	{
		sys->hooks.isrightclickdown = 0;
		sys->hooks.rightclickdownpos[X] = x;
		sys->hooks.rightclickdownpos[Y] = y;
	}
	return (0);
}

int	mousemove(int x, int y, t_system *sys)
{
	int	rc[2];

	if (sys->hooks.isrightclickdown)
	{
		rc[X] = (x - sys->hooks.rightclickdownpos[X]);
		rc[Y] = (y - sys->hooks.rightclickdownpos[Y]);
		translate(&sys->map, (int)rc[X], (int)rc[Y]);
		sys->hooks.rightclickdownpos[X] = x;
		sys->hooks.rightclickdownpos[Y] = y;
	}
	if (sys->hooks.isleftclickdown)
	{
		change_angle(sys, x, y);
		rotate(sys);
	}
	if (sys->map.change)
		render(sys);
	return (0);
}
