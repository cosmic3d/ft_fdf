/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:02:58 by jenavarr          #+#    #+#             */
/*   Updated: 2022/06/01 16:30:00 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_print_str(char *str)
{
	int	i;
	int	w;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
	{
		w = ft_print_char(str[i]);
		if (w == -1)
			return (-1);
		i++;
	}
	return (i);
}
