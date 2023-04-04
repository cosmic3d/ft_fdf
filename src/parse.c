/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 19:30:41 by jenavarr          #+#    #+#             */
/*   Updated: 2023/04/04 15:53:05 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/fdf.h"

unsigned int	hexstr_to_int(char *str)
{
	unsigned int	result;
	int				shift;
	int				i;

	result = 0;
	shift = 0;
	i = ft_strlen(str);
	while (--i >= 0)
	{
		if (str[i] >= '0' && str[i] <= '9')
			result |= (str[i] - '0') << shift;
		else
			result |= (uppercase(str[i]) - 'A') << shift;
		shift += 4;
	}
	return (result);
}

unsigned int	compose_color(unsigned int value, int endian)
{
	unsigned char	*bytes;
	unsigned int	color;

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
