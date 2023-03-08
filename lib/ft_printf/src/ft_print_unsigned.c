/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 20:11:16 by jenavarr          #+#    #+#             */
/*   Updated: 2022/06/06 20:11:21 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_print_unsigned(unsigned int i)
{
	ssize_t	len;
	int		w;

	len = 0;
	if (i >= 10)
	{
		len += ft_print_unsigned(i / 10);
		if (len == -1)
			return (-1);
		len += ft_print_unsigned(i % 10);
	}
	else
	{
		w = ft_print_char(i + '0');
		if (w == -1)
			return (-1);
		len += w;
	}
	return (len);
}
