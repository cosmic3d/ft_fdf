/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:35:00 by jenavarr          #+#    #+#             */
/*   Updated: 2022/05/16 17:35:04 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s1) - 1;
	if (!s1 || !set)
		return (NULL);
	while (s1[i] != '\0' && ft_strchr(set, (int)s1[i]))
	{
		i++;
	}
	while (len >= 0 && ft_strchr(set, (int)s1[len]))
	{
		len--;
	}
	return (ft_substr(s1, i, len - i + 1));
}
