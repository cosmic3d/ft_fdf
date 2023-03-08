/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:04:28 by jenavarr          #+#    #+#             */
/*   Updated: 2023/03/08 20:44:27 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/fdf.h"

void	f_exit(char *err_message)
{
	ft_printf("%s\n", err_message);
	exit(1);
}

int	check_filename(char *file)
{
	int	last;

	last = ft_strlen(file) - 1;
	if (ft_strlen(file) < ft_strlen(".fdf") + 1)
		return (0);
	if (file[last] != 'f' || file[last - 1] != 'd' || file[last - 2] != 'f')
		return (0);
	if (file[last - 3] != '.')
		return (0);
	return (1);
}
