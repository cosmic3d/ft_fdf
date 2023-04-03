/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:36:47 by jenavarr          #+#    #+#             */
/*   Updated: 2023/04/03 16:43:46 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/fdf.h"

void	debug_split(char **strings)
{
	ft_printf("\"%s\"\n", *strings);
	while (*strings)
	{
		strings++;
		ft_printf("\"%s\"\n", *strings);
	}
}
