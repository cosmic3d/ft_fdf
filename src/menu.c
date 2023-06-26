/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 21:00:40 by jenavarr          #+#    #+#             */
/*   Updated: 2023/06/26 22:11:23 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/fdf.h"

void	print_info(t_system *sys)
{
	print_angle(sys);
}

void	print_angle(t_system *sys)
{
	char	*x;
	char	*y;
	char	*z;

	x = ft_itoa(sys->view.angle[X]);
	y = ft_itoa(sys->view.angle[Y]);
	z = ft_itoa(sys->view.angle[Z]);
	mlx_string_put(sys->mlx_ptr, sys->mlx_win, M_TAB, 100, 0xFF0000, "X:");
	mlx_string_put(sys->mlx_ptr, sys->mlx_win, M_TAB + M_SEP, 100, 0xFF0000, x);
	mlx_string_put(sys->mlx_ptr, sys->mlx_win, M_TAB, 125, 0xFF0000, "Y:");
	mlx_string_put(sys->mlx_ptr, sys->mlx_win, M_TAB + M_SEP, 125, 0xFF0000, y);
	mlx_string_put(sys->mlx_ptr, sys->mlx_win, M_TAB, 150, 0xFF0000, "Z:");
	mlx_string_put(sys->mlx_ptr, sys->mlx_win, M_TAB + M_SEP, 150, 0xFF0000, z);
	free(x);
	free(y);
	free(z);
}
