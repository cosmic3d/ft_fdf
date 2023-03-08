/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:00:32 by jenavarr          #+#    #+#             */
/*   Updated: 2022/05/11 18:45:27 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	j;

	dest_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = dest_len;
	j = 0;
	if (dest_len > dstsize || dstsize == 0)
	{
		return (dstsize + src_len);
	}
	else
	{
		while (i < dstsize - 1 && src[j] != '\0')
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = '\0';
	}
	return (src_len + dest_len);
}
