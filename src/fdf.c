/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:27:04 by jenavarr          #+#    #+#             */
/*   Updated: 2023/03/25 01:12:44 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/fdf.h"

void	init_system(t_system *sys)
{
	sys->mlx_ptr = mlx_init();
	if (!sys->mlx_ptr)
		f_exit("Mlx pointer creation failed");
	sys->mlx_win = mlx_new_window(sys->mlx_ptr, WINX, WINY, "cosmic3d FDF");
	if (!sys->mlx_win)
		f_exit("Mlx window creation failed");
	sys->img = get_img(sys);
	put_pixel(sys->img, 10, 10, 0xFFFFFF);
	mlx_put_image_to_window(sys->mlx_ptr, sys->mlx_win, sys->img->img, 0, 0);
	mlx_loop(sys->mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_system	sys;

	check_all(argc, argv);
	init_system(&sys);
	return (0);
}
