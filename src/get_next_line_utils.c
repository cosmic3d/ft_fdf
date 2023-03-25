/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 21:30:06 by jenavarr          #+#    #+#             */
/*   Updated: 2023/03/17 19:03:25 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/get_next_line.h"

char	*ftg_strjoin(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		j;

	i = -1;
	j = 0;
	new = (void *)ftg_calloc((size_t)(ft_strlen(s1) + ft_strlen(s2) + 1));
	if (new == NULL)
		return (freeshit(&s1));
	while (s1[++i] != '\0')
		new[i] = s1[i];
	while (s2[j] != '\0')
	{
		new[i] = s2[j];
		j++;
		i++;
	}
	freeshit(&s1);
	return (new);
}

int	ft_strlen(const char *str)
{
	int	length;

	length = 0;
	if (!str)
		return (0);
	while (str[length])
		length++;
	return (length);
}

void	*ftg_calloc(size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = (char *)malloc(sizeof(char) * size);
	if (!ptr)
		return (NULL);
	while (i < size)
		ptr[i++] = 0;
	return (ptr);
}

char	*ftg_strrchr(const char *s, int c, int index)
{
	if (s)
	{
		while (s[index] != '\0')
		{
			if (s[index] == (char)c)
				return ((char *)(s + index));
			index++;
		}
	}
	return (NULL);
}
