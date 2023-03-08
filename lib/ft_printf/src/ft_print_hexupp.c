/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexupp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 18:29:52 by jenavarr          #+#    #+#             */
/*   Updated: 2022/06/06 18:29:57 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_print_hexupp(unsigned long long dec)
{
	ssize_t	len;
	int		w;

	len = 0;
	if (dec >= 16)
	{
		len += ft_print_hexupp(dec / 16);
		if (len == -1)
			return (-1);
		len += ft_print_hexupp(dec % 16);
	}
	else
	{
		w = ft_print_char("0123456789ABCDEF"[dec]);
		if (w == -1)
			return (-1);
		len += w;
	}
	return (len);
}
