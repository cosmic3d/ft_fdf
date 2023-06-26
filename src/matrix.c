/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 19:22:55 by jenavarr          #+#    #+#             */
/*   Updated: 2023/06/26 22:34:58 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/fdf.h"

void	initialize_matrix(t_matrix *m)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
			m->matrix[i][j] = 0;
	}
	return ;
}

t_matrix	multiply_matrices(t_matrix one, t_matrix two)
{
	t_matrix	new;
	int			i;
	int			j;
	int			k;

	initialize_matrix(&new);
	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
		{
			k = -1;
			while (++k < 3)
				new.matrix[i][j] += one.matrix[i][k] * two.matrix[k][j];
		}
	}
	return (new);
}

t_matrix	get_rxyz(t_system *sys)
{
	t_matrix	rx;
	t_matrix	ry;
	t_matrix	rz;

	initialize_matrix(&rx);
	initialize_matrix(&ry);
	initialize_matrix(&rz);
	rx.matrix[0][0] = 1;
	rx.matrix[1][1] = cos(deg_to_rad(sys->view.angle[X]));
	rx.matrix[1][2] = -sin(deg_to_rad(sys->view.angle[X]));
	rx.matrix[2][1] = sin(deg_to_rad(sys->view.angle[X]));
	rx.matrix[2][2] = cos(deg_to_rad(sys->view.angle[X]));
	ry.matrix[1][1] = 1;
	ry.matrix[0][0] = cos(deg_to_rad(sys->view.angle[Y]));
	ry.matrix[0][2] = sin(deg_to_rad(sys->view.angle[Y]));
	ry.matrix[2][0] = -sin(deg_to_rad(sys->view.angle[Y]));
	ry.matrix[2][2] = cos(deg_to_rad(sys->view.angle[Y]));
	rz.matrix[2][2] = 1;
	rz.matrix[0][0] = cos(deg_to_rad(sys->view.angle[Z]));
	rz.matrix[0][1] = -sin(deg_to_rad(sys->view.angle[Z]));
	rz.matrix[1][0] = sin(deg_to_rad(sys->view.angle[Z]));
	rz.matrix[1][1] = cos(deg_to_rad(sys->view.angle[Z]));
	return (multiply_matrices(multiply_matrices(rz, ry), rx));
}

void	rotate_point(t_point *p, t_matrix rxyz)
{
	int		i;
	int		j;
	float	tmp;

	i = -1;
	while (++i < 3)
	{
		j = -1;
		tmp = 0;
		while (++j < 3)
			tmp += p->scopypos[j] * rxyz.matrix[i][j];
		p->spos[i] = tmp;
	}
	return ;
}
