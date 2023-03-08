/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:06:18 by jenavarr          #+#    #+#             */
/*   Updated: 2022/05/12 18:19:13 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	chr;

	chr = (unsigned char)c;
	while (n != 0)
	{
		if (*(unsigned char *)s == chr)
			return ((void *)s);
		n--;
		s++;
	}
	return (NULL);
}
