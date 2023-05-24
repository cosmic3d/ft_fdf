/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 19:30:41 by jenavarr          #+#    #+#             */
/*   Updated: 2023/05/24 14:55:40 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/fdf.h"

int	hexstr_to_int(char *str)
{
	int	result;

	result = strtol(str + 2, NULL, 16);
	// if (ft_strlen(str) - 2 <= 6)
	// 	result |= 0xFF000000;
	return (result);
}

int	compose_color(int value, int endian)
{
	int	color;
	unsigned char	*bytes;

	bytes = (unsigned char *)&value;
	color = 0;
	if (!endian)
	{
		color |= bytes[0];
		color |= bytes[1] << 8;
		color |= bytes[2] << 16;
		color |= bytes[3] << 24;
		return (color);
	}
	color |= bytes[3];
	color |= bytes[2] << 8;
	color |= bytes[1] << 16;
	color |= bytes[0] << 24;
	return (color);
}

double	deg_to_rad(float degrees)
{
	double	radians;

	radians = degrees * (M_PI / 180.0);
	return (radians);
}

float	get_abs(float num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}
