/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:27:04 by jenavarr          #+#    #+#             */
/*   Updated: 2023/03/08 18:40:54 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/fdf.h"

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (1); //Use strerrror
	win_ptr = mlx_new_window (mlx_ptr, 300, 300, "Hello World");
	if (!win_ptr)
		return (2);
	mlx_loop(mlx_ptr);
	return (0);
}
