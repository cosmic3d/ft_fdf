/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:21:51 by jenavarr          #+#    #+#             */
/*   Updated: 2022/06/01 15:48:09 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_print_ptr(unsigned long long ptr)
{
	int	len;

	len = 0;
	if (write(1, "0x", 2) != 2)
		return (-1);
	if (ptr == 0)
	{
		if (write(1, "0", 1) != 1)
			return (-1);
		return (3);
	}
	len += ft_print_hexlow(ptr);
	if (len == -1)
		return (-1);
	return (len + 2);
}
