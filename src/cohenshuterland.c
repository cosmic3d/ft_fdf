/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cohenshuterland.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:55:49 by jenavarr          #+#    #+#             */
/*   Updated: 2023/06/16 19:58:02 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/fdf.h"

int	computeoutcode(float x, float y)
{
	int	code;

	code = 0;
	if (x < 0)
		code |= 0b0001;
	else if (x > WINX)
		code |= 0b0010;
	if (y < 0)
		code |= 0b0100;
	else if (y > WINY)
		code |= 0b1000;
	return (code);
}

int	cohensutherland(t_point p1, t_point p2)
{
	int		code[2];
	float	xy[2];
	int		codeout;

	code[0] = computeoutcode(p1.spos[X], p1.spos[Y]);
	code[1] = computeoutcode(p2.spos[X], p2.spos[Y]);
	while (1)
	{
		if (code[0] == 0 && code[1] == 0)
			return (1);
		if (code[0] & code[1])
			return (0);
		codeout = cohenshuterland_3(codeout, code);
		cohensutherland_2(p1, p2, codeout, xy);
		if (codeout == code[0])
		{
			p1.spos[X] = xy[X];
			p1.spos[Y] = xy[Y];
			code[0] = computeoutcode(p1.spos[X], p1.spos[Y]);
			continue ;
		}
		p2.spos[X] = xy[X];
		p2.spos[Y] = xy[Y];
		code[1] = computeoutcode(p2.spos[X], p2.spos[Y]);
	}
}

void	cohensutherland_2(t_point p1, t_point p2, int codeout, float *xy)
{
	if (codeout & 0b1000)
	{
		xy[X] = p1.spos[X] + (p2.spos[X] - p1.spos[X]) * (WINY - p1.spos[Y]) \
		/ (p2.spos[Y] - p1.spos[Y]);
		xy[Y] = WINY;
	}
	else if (codeout & 0b0100)
	{
		xy[X] = p1.spos[X] + (p2.spos[X] - p1.spos[X]) * (0 - p1.spos[Y]) \
		/ (p2.spos[Y] - p1.spos[Y]);
		xy[Y] = 0;
	}
	else if (codeout & 0b0010)
	{
		xy[Y] = p1.spos[Y] + (p2.spos[Y] - p1.spos[Y]) * (WINX - p1.spos[X]) \
		/ (p2.spos[X] - p1.spos[X]);
		xy[X] = WINX;
	}
	else if (codeout & 0b0001)
	{
		xy[Y] = p1.spos[Y] + (p2.spos[Y] - p1.spos[Y]) * (0 - p1.spos[X]) \
		/ (p2.spos[X] - p1.spos[X]);
		xy[X] = 0;
	}
}

int	cohenshuterland_3(int codeout, int *code)
{
	codeout = code[1];
	if (code[0])
		codeout = code[0];
	return (codeout);
}
