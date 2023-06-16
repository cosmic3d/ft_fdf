/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 20:50:44 by jenavarr          #+#    #+#             */
/*   Updated: 2023/06/16 19:43:36 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/fdf.h"

int	mousedown(int button, int x, int y, t_system *sys)
{
	if (x < 0 || x > WINX || y < 0 || y > WINY)
		return (0);
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
	if (x < 0 || x > WINX || y < 0 || y > WINY)
		return (0);
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

	if (x < 0 || x > WINX || y < 0 || y > WINY)
		return (0);
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
		change_angle_with_mouse(sys, x, y);
		rotate(sys);
	}
	if (sys->map.change)
		render(sys);
	return (0);
}
