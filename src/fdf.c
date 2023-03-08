/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:27:04 by jenavarr          #+#    #+#             */
/*   Updated: 2023/03/08 20:23:50 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/fdf.h"

int	main(int argc, char **argv)
{
	if (argc == 1)
		f_exit("You need to introduce a map to represent");
	else if (argc >= 3)
		f_exit("Too many maps!");
	if (!check_filename(argv[1]))
		f_exit("The file you introduced is not a .fdf file");
	return (0);
}
