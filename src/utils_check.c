/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:04:28 by jenavarr          #+#    #+#             */
/*   Updated: 2023/03/24 21:26:42 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/fdf.h"

void	check_all(int argc, char **argv)
{
	int		fd;

	if (argc == 1)
		f_exit("You need to introduce a map to represent");
	else if (argc >= 3)
		f_exit("Too many maps!");
	if (!check_filename(argv[1]))
		f_exit("The file you introduced is not a .fdf file");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error");
		exit(1);
	}
	if (!check_rectangle(fd))
		f_exit("The map you introduced is not a rectangle!");
}

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

int	count_columns(int fd)
{
	char	*line;
	char	**points;
	int		i;

	i = 0;
	line = get_next_line(fd);
	if (!line)
		return (0);
	points = ft_split(line, ' ');
	if (!points)
		return (0);
	while (points[i])
		i++;
	ft_free(points);
	free(line);
	return (i - 1);
}

int	check_rectangle(int fd)
{
	int		line1;
	int		line;

	line1 = count_columns(fd);
	if (!line1)
		return (0);
	line = count_columns(fd);
	if (line1 != line)
		return (0);
	while (line)
	{
		if (line1 != line)
			return (0);
		line = count_columns(fd);
	}
	return (1);
}
