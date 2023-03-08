/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:13:50 by jenavarr          #+#    #+#             */
/*   Updated: 2022/05/13 18:50:49 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (*needle == '\0')
		return ((char *)haystack);
	else if (*haystack == '\0')
		return (0);
	else if (len < (size_t)ft_strlen(needle))
		return (0);
	i = 0;
	while (*haystack)
	{
		if (*haystack == *needle)
		{
			j = 0;
			while (haystack[j] == needle[j] && needle[j] && (i + j) < len)
				j++;
			if (needle[j] == 0)
				return ((char *)haystack);
		}
		i++;
		haystack++;
	}
	return (0);
}
