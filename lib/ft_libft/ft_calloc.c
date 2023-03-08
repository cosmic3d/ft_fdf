/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 13:32:20 by jenavarr          #+#    #+#             */
/*   Updated: 2022/05/15 13:46:34 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*pointer;

	pointer = malloc(nitems * size);
	if (pointer == 0)
		return (pointer);
	ft_bzero(pointer, nitems * size);
	return (pointer);
}
