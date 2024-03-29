/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 20:01:39 by jenavarr          #+#    #+#             */
/*   Updated: 2023/04/23 18:41:09 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/fdf.h"

int	count_char(char *str, char c)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (str[++i])
		if (str[i] == c)
			count++;
	return (count);
}

int	forbidden_chars(char *str, char *allowed)
{
	int	i;

	i = -1;
	while (str[++i] && str[i] != '\n')
		if (!ft_strrchr(allowed, str[i]))
			return (1);
	return (0);
}

void	check_hexadecimal(char *str, char ***tofree)
{
	int	len;

	len = ft_strlen(str);
	if (!(str[0] == '0' && (str[1] == 'x' || str[1] == 'X')) || len > 10)
	{
		ft_free(*tofree);
		f_exit("Your hexadecimal number is wrong");
	}
	str += 2;
	if (forbidden_chars(str, "0123456789abcdefABCDEF"))
	{
		ft_free(*tofree);
		f_exit("Your hexadecimal number is wrong");
	}
}

char	uppercase(char c)
{
	if ((c < 'a' || c > 'z') || (c < 'A' || c > 'Z'))
		return (0);
	if ((c >= 'a' && c <= 'z'))
		c -= 32;
	return (c);
}

void	erase_new_line(char *line)
{
	int	i;

	i = -1;
	while (line && line[++i])
		if (line[i] == '\n')
			line[i] = '\0';
}
