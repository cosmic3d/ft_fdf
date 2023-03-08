/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:16:27 by jenavarr          #+#    #+#             */
/*   Updated: 2022/05/12 18:16:32 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 1;
	while (*str == ' ' || *str == '\n' || *str == '\v' || *str == '\t'
		|| *str == '\f' || *str == '\r')
		str++;
	if (*str == '-')
	{
		n = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		i = i * 10 + (*str - '0');
		str++;
	}
	return (i * n);
}
