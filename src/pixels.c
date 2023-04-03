/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 23:08:28 by jenavarr          #+#    #+#             */
/*   Updated: 2023/04/03 17:52:30 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/fdf.h"

t_data	*get_img(t_system *sys)
{
	t_data	*dt;

	dt = (t_data *)malloc(sizeof(t_data));
	dt->img = mlx_new_image(sys->mlx_ptr, WINX, WINY);
	dt->addr = mlx_get_data_addr(dt->img, &dt->bpp, &dt->line, &dt->endian);
	if (!dt->addr)
		f_exit("An error occurred during image creation");
	return (dt);
}

void	put_pixel(t_data *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line) + (x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}
