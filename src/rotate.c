/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 20:58:29 by jenavarr          #+#    #+#             */
/*   Updated: 2023/06/15 21:09:41 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/fdf.h"

void	rot_x(t_system *sys, t_point *p, t_point *tmp)
{
	tmp->scopypos[Y] -= sys->map.center.spos[Y];
	tmp->scopypos[Y] = tmp->scopypos[Y] * cos(deg_to_rad(sys->view.angle[X])) \
	- tmp->scopypos[Z] * sin(deg_to_rad(sys->view.angle[X]));
	tmp->scopypos[Z] = tmp->scopypos[Y] * sin(deg_to_rad(sys->view.angle[X])) \
	+ tmp->scopypos[Z] * cos(deg_to_rad(sys->view.angle[X]));
	tmp->scopypos[Y] += sys->map.center.spos[Y];
	p->spos[Y] = tmp->scopypos[Y];
	p->spos[Z] = tmp->scopypos[Z];
}

void	rot_y(t_system *sys, t_point *p, t_point *tmp)
{
	tmp->scopypos[X] -= sys->map.center.spos[X];
	tmp->scopypos[X] = tmp->scopypos[X] * cos(deg_to_rad(sys->view.angle[Y])) \
	+ tmp->scopypos[Z] * sin(deg_to_rad(sys->view.angle[Y]));
	tmp->scopypos[Z] = tmp->scopypos[X] * -sin(deg_to_rad(sys->view.angle[Y])) \
	+ tmp->scopypos[Z] * cos(deg_to_rad(sys->view.angle[Y]));
	tmp->scopypos[X] += sys->map.center.spos[X];
	p->spos[X] = tmp->scopypos[X];
	p->spos[Z] = tmp->scopypos[Z];
}

void	rot_z(t_system *sys, t_point *p, t_point *tmp)
{
	tmp->scopypos[Y] -= sys->map.center.spos[Y];
	tmp->scopypos[X] -= sys->map.center.spos[X];
	tmp->scopypos[X] = tmp->scopypos[X] * cos(deg_to_rad(sys->view.angle[Z])) \
	- tmp->scopypos[Y] * sin(deg_to_rad(sys->view.angle[Z]));
	tmp->scopypos[Y] = tmp->scopypos[X] * sin(deg_to_rad(sys->view.angle[Z])) \
	+ tmp->scopypos[Y] * cos(deg_to_rad(sys->view.angle[Z]));
	tmp->scopypos[Y] += sys->map.center.spos[Y];
	tmp->scopypos[X] += sys->map.center.spos[X];
	p->spos[X] = tmp->scopypos[X];
	p->spos[Y] = tmp->scopypos[Y];
}
