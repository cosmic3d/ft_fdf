/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:27:04 by jenavarr          #+#    #+#             */
/*   Updated: 2023/04/16 18:40:52 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/fdf.h"

void	init_system(t_system *sys)
{
	int	fd;

	sys->mlx_ptr = mlx_init();
	if (!sys->mlx_ptr)
		f_exit("Mlx pointer creation failed");
	sys->mlx_win = mlx_new_window(sys->mlx_ptr, WINX, WINY, "cosmic3d FDF");
	if (!sys->mlx_win)
		f_exit("Mlx window creation failed");
	sys->img = get_img(sys);
	fd = open(sys->filename, O_RDONLY);
	load_map(sys, fd);
	close(fd);
	ft_printf("Number of points is: %i\n", sys->map.length);
	ft_printf("Number of points per line is: %i\n", sys->map.ll);
	hook(sys);
	init_view(sys);
	render(sys);
	mlx_loop(sys->mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_system	sys;

	check_all(argc, argv, &sys.map);
	sys.filename = argv[1];
	init_system(&sys);
	return (0);
}
