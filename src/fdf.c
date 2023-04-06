/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:27:04 by jenavarr          #+#    #+#             */
/*   Updated: 2023/04/06 20:47:40 by jenavarr         ###   ########.fr       */
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
	// put_pixel(sys->img, 10, 10, 0xFFFFFF);
	// draw_line(sys, (int []){0, 0}, (int []){1920, 1080}, 0xFFFFFF);
	ft_printf("Number of points is: %i\n", sys->map.length);
	ft_printf("Number of points per line is: %i\n", sys->map.ll);
	render(sys);
	// debug_points(sys);
	// debug_line(sys);
	mlx_hook(sys->mlx_win, 17, 0, f_exit, "");
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
