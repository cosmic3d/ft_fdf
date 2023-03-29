/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 20:01:39 by jenavarr          #+#    #+#             */
/*   Updated: 2023/03/29 21:24:49 by jenavarr         ###   ########.fr       */
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
	int	j;
	int	valid_one;

	i = -1;
	valid_one = 0;
	while (str[++i] && valid_one == 0)
	{
		j = -1;
		valid_one = 1;
		while (allowed[++j])
		{
			if (str[i] == allowed[j])
			{
				valid_one = 0;
				break ;
			}
		}
	}
	return (valid_one);
}

int	check_hexadecimal(char *str, char ***tofree)
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

int	check_int(char **s)
{
	int	i;
	int	sign;

	i = 0;
	sign = 0;
	while (s[++i])
	{
		if (s[i][0] == '-' || s[i][0] == '+')
			sign = 1;
		if (ft_strlen(s[i]) - sign > 10)
			return (0);
		if (ft_strlen(s[i]) - sign == 10)
			if (!check_limits_when_10(s[i], sign))
				return (0);
	}
	return (1);
}

int	check_limits_when_10(char *str, int sign)
{
	if (sign)
	{
		if (str[0] == '+')
		{
			if (ft_strncmp(str, "+2147483647", 11) > 0)
				return (0);
		}
		else
		{
			if (ft_strncmp(str, "-2147483648", 11) > 0)
				return (0);
		}
	}
	if (ft_strncmp(str, "2147483647", 10) > 0)
		return (0);
	return (1);
}
