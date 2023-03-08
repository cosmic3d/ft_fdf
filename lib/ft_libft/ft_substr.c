/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 16:57:47 by jenavarr          #+#    #+#             */
/*   Updated: 2022/05/16 15:41:11 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	char	*new;
	size_t	i;

	size = 0;
	i = 0;
	while (s[i++])
		size++;
	i = 0;
	if (start >= size)
		new = malloc(sizeof(char) * 1);
	else if (len > size - start)
		new = malloc(sizeof(char) * (size - start + 1));
	else
		new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	while (start + i < size && i < len)
	{
		new[i] = s[i + start];
		i++;
	}
	new[i] = '\0';
	return (new);
}
