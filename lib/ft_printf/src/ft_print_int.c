/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:55:45 by jenavarr          #+#    #+#             */
/*   Updated: 2022/06/03 12:39:54 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	funci(ssize_t *len, int *i, int *w)
{
	if (*i > 9)
	{
		*len += ft_print_int(*i / 10);
		if (*len == -1)
			return (-1);
		*len += ft_print_int(*i % 10);
	}
	else
	{
		*w = ft_print_char(*i + '0');
		if (*w == -1)
			return (-1);
		*len += *w;
	}
	return (0);
}

int	ft_print_int(int i)
{
	ssize_t	len;
	int		w;

	len = 0;
	if (i == -2147483648)
		return (ft_print_str("-2147483648"));
	if (i < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		len = 1;
		i *= -1;
	}
	if (funci(&len, &i, &w) == -1)
		return (-1);
	return (len);
}
