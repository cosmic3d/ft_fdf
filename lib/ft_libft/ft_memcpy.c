/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:52:18 by jenavarr          #+#    #+#             */
/*   Updated: 2022/05/10 15:26:41 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*cdst;
	char	*csrc;

	csrc = (void *)src;
	cdst = dst;
	i = 0;
	if (!dst && !src)
	{
		return (0);
	}
	while (i < n)
	{
		cdst[i] = csrc[i];
		i++;
	}
	return (dst);
}
