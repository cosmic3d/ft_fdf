/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 19:39:26 by jenavarr          #+#    #+#             */
/*   Updated: 2022/05/09 20:08:45 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *s, int c, unsigned int len)
{
	unsigned char	*p;

	p = s;
	while (len--)
	{
		*p++ = (unsigned char)c;
	}
	return (s);
}
