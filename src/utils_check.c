/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:04:28 by jenavarr          #+#    #+#             */
/*   Updated: 2023/05/12 13:30:57 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/fdf.h"

void	check_all(int argc, char **argv, t_map *map)
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
	if (!check_valid(fd, map))
		f_exit("The map you introduced is not a rectangle!");
	close(fd);
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

int	count_or_check_line(int fd)
{
	char	*line;
	char	**points;
	int		i;

	i = 0;
	line = get_next_line(fd);
	erase_new_line(line);
	if (!line)
		return (0);
	if (forbidden_chars(line, "0123456789abcdefABCDEF, xX-+"))
		f_exit("Forbidden characters were detected");
	if (!ft_strchr(line, ' '))
		f_exit("Map syntax error");
	points = ft_split(line, ' ');
	if (!points)
		f_exit("Split failed");
	check_line_points(points);
	while (points[i])
		i++;
	ft_free(points);
	free(line);
	return (i);
}

int	check_valid(int fd, t_map *map)
{
	int		line1;
	int		line;

	line1 = count_or_check_line(fd);
	map->ll = line1;
	map->length += line1;
	if (!line1)
		return (0);
	line = count_or_check_line(fd);
	if (line1 != line)
		return (0);
	while (line)
	{
		if (line1 != line)
			return (0);
		line = count_or_check_line(fd);
		map->length += line1;
	}
	return (1);
}

void	check_line_points(char **line)
{
	int		i;
	char	**vals;

	i = -1;
	while (line[++i] && line[i][0] != '\n' && line)
	{
		vals = ft_split(line[i], ',');
		if (count_char(line[i], ',') > 1)
			f_exit("Syntax error on some point, too many commas");
		else if (count_char(line[i], ',') == 1)
		{
			if (!vals || !vals[1])
				f_exit("Split allocation error");
			check_hexadecimal(vals[1], &vals);
		}
		if (forbidden_chars(*vals, "0123456789+-") || !check_num(*vals))
			f_exit("The Y value of a point is not a valid integer");
		ft_free(vals);
	}
}
