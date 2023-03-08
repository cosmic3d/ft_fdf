/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:23:42 by jenavarr          #+#    #+#             */
/*   Updated: 2022/05/13 18:58:06 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == (unsigned char)c)
		{
			return ((char *)str);
		}
		str++;
	}
	if (*str == (unsigned char)c)
	{
		return ((char *)str);
	}
	return (NULL);
}
