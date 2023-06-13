/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 20:58:29 by jenavarr          #+#    #+#             */
/*   Updated: 2023/06/13 21:18:21 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/fdf.h"

void	rot_x(t_system *sys, t_point *p)
{
	p->spos[Y] = p->scopypos[Y] * cos(deg_to_rad(sys->view.angle[X])) \
	- p->scopypos[Z] * sin(deg_to_rad(sys->view.angle[X]));
	p->spos[Z] = p->scopypos[Y] * sin(deg_to_rad(sys->view.angle[X])) \
	+ p->scopypos[Z] * cos(deg_to_rad(sys->view.angle[X]));
}

void	rot_y(t_system *sys, t_point *p)
{
	p->spos[X] = p->scopypos[X] * cos(deg_to_rad(sys->view.angle[Y])) \
	+ p->scopypos[Z] * sin(deg_to_rad(sys->view.angle[Y]));
	p->spos[Z] = p->scopypos[X] * -sin(deg_to_rad(sys->view.angle[Y])) \
	+ p->scopypos[Z] * cos(deg_to_rad(sys->view.angle[Y]));
}

void	rot_z(t_system *sys, t_point *p)
{
	p->spos[X] = p->scopypos[X] * cos(deg_to_rad(sys->view.angle[Z])) \
	- p->scopypos[Y] * sin(deg_to_rad(sys->view.angle[Z]));
	p->spos[Y] = p->scopypos[X] * sin(deg_to_rad(sys->view.angle[Z])) \
	+ p->scopypos[Y] * cos(deg_to_rad(sys->view.angle[Z]));
}
