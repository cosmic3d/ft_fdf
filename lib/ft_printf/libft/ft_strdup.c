/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 15:29:28 by jenavarr          #+#    #+#             */
/*   Updated: 2022/05/15 16:25:28 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <errno.h>

char	*ft_strdup(const char *s1)
{
	char	*copy;
	int		i;

	i = ft_strlen(s1);
	copy = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (copy == 0)
	{
		errno = ENOMEM;
		return (NULL);
	}
	while (i >= 0)
	{
		copy[i] = s1[i];
		i--;
	}
	return (copy);
}
