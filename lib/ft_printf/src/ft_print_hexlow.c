/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexlow.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 18:01:47 by jenavarr          #+#    #+#             */
/*   Updated: 2022/06/06 18:02:58 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_print_hexlow(unsigned long long dec)
{
	ssize_t	len;
	int		w;

	len = 0;
	if (dec >= 16)
	{
		len += ft_print_hexlow(dec / 16);
		if (len == -1)
			return (-1);
		len += ft_print_hexlow(dec % 16);
	}
	else
	{
		w = ft_print_char("0123456789abcdef"[dec]);
		if (w == -1)
			return (-1);
		len += w;
	}
	return (len);
}
