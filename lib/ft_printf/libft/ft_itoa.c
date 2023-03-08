/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 17:22:08 by jenavarr          #+#    #+#             */
/*   Updated: 2022/05/19 13:30:10 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	get_digits(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*get_num(char *str, int n, int sign)
{
	int	i;

	i = get_digits(n);
	if (sign == -1)
	{
		str[0] = '-';
		str[i + 1] = '\0';
		while (n != 0)
		{
			str[i] = ((n * -1) % 10) + '0';
			n /= 10;
			i--;
		}
		return (str);
	}
	str[i--] = '\0';
	while (n != 0)
	{
		str[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*new;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
	{
		new = malloc(sizeof(char) * (get_digits(n) + 2));
		if (!new)
			return ("-1");
		new = get_num(new, n, -1);
		return (new);
	}
	else
	{
		new = malloc(sizeof(char) * (get_digits(n) + 1));
		if (!new)
			return (0);
		new = get_num(new, n, 1);
		return (new);
	}
}

// int main(void)
// {
//     printf("%s\n", ft_itoa(-22));
//     return 0;
// }
