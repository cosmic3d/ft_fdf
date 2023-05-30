/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 18:19:48 by jenavarr          #+#    #+#             */
/*   Updated: 2023/05/30 21:32:44 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/fdf.h"

void	hook(t_system *sys)
{
	mlx_hook(sys->mlx_win, 17, 0, f_exit, "");
	mlx_hook(sys->mlx_win, 2, 0, keypressed, sys);
	mlx_hook(sys->mlx_win, BUTTON_MOUSEDOWN, 0, mousedown, sys);
	if (sys->hooks.isleftclickdown || sys->hooks.isrightclickdown)
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
	// if (button == MOUSE_SCROLLDOWN)
	// 	translate(&sys->map, TRANSLATE, 0);
	// if (button == MOUSE_SCROLLUP)
	// 	translate(&sys->map, 0, TRANSLATE);
	if (button == MOUSE_SCROLLDOWN)
		scale(&sys->map, ZOOM);
	if (button == MOUSE_SCROLLUP)
		scale(&sys->map, -ZOOM);
	if (sys->map.change)
		render(sys);
	return (0);
}

int	mouseup(int button, int x, int y, t_system *sys)
{
	if (button == MOUSE_LEFTCLICK)
	{
		sys->hooks.isleftclickdown = 0;
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

	// int	lc[2];
	if (sys->hooks.isrightclickdown)
	{
		rc[X] = (x - sys->hooks.rightclickdownpos[X]);
		rc[Y] = (y - sys->hooks.rightclickdownpos[Y]);
		translate(&sys->map, (int)rc[X], (int)rc[Y]);
		sys->hooks.rightclickdownpos[X] = x;
		sys->hooks.rightclickdownpos[Y] = y;
	}
	if (sys->map.change)
		render(sys);
	return (0);
}
