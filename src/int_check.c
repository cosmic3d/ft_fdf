/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:59:45 by jenavarr          #+#    #+#             */
/*   Updated: 2023/04/03 16:04:12 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/fdf.h"

int	check_num(char *str)
{
	int	j;

	j = 0;
	if (str[j] == '-' || str[j] == '+')
		j++;
	if (str[j] == '-' || str[j] == '+' || str[j] == '\0')
		return (0);
	while (str[j] != '\0')
	{
		if (str[j] < '0' || str[j] > '9')
			return (0);
		j++;
	}
	return (check_int(str));
}

int	check_int(char *s)
{
	int	sign;

	sign = 0;
	if (s[0] == '-' || s[0] == '+')
		sign = 1;
	if (ft_strlen(s) - sign > 10)
		return (0);
	if (ft_strlen(s) - sign == 10)
		if (!check_limits_when_10(s, sign))
			return (0);
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
