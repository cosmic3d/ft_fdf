/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 19:30:41 by jenavarr          #+#    #+#             */
/*   Updated: 2023/04/03 21:51:10 by jenavarr         ###   ########.fr       */
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
