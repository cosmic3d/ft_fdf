/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:35:54 by jenavarr          #+#    #+#             */
/*   Updated: 2022/06/09 19:47:26 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static char	**ft_free(char **str, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static int	word_count(char *str, char separator)
{
	int	i;
	int	counter;

	counter = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != separator && i == 0)
			counter++;
		if (str[i] == separator && str[i + 1] != separator && str[i + 1])
			counter++;
		i++;
	}
	return (counter);
}

static char	**loc_mem(char *str, char s)
{
	int		i;
	int		j;
	int		w;
	int		wordc;
	char	**words;

	wordc = word_count(str, s);
	words = malloc(sizeof(char *) * (wordc + 1));
	if (!words)
		return (0);
	j = 0;
	i = -1;
	while (++i < wordc)
	{
		w = 0;
		while (str[j] == s)
			j++;
		while ((str[j] && str[j] != s)
			&& ((j == 0 && str[j] != s) || (str[j] != s)) && w++ != -1)
			j++;
		words[i] = malloc(sizeof(char) * (w + 1));
		if (!words[i])
			return (ft_free(words, i));
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**words;

	words = loc_mem((char *)s, c);
	if (!words)
		return (0);
	i = 0;
	j = 0;
	while (i < word_count((char *)s, c))
	{
		k = 0;
		while ((char)s[j] == c)
			j++;
		if ((j == 0 && (char)s[j] != c) || ((char)s[j] != c && (char)s[j]))
		{
			while ((char)s[j] && (char)s[j] != c)
				words[i][k++] = (char)s[j++];
			words[i][k] = '\0';
		}
		i++;
	}
	words[i] = NULL;
	return (words);
}

//int main(void)
//{
//	int		i;
//	char	**words;
//	const char	str[] = "Hello!";
//	words = ft_split(str, ' ');
//	i = 0;
//
//	while (i <= word_count((char *)str, ' '))
//	{
//		printf("Output is: %s\n", words[i]);
//		i++;
//	}
//	return 0;
//}
