/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 14:48:46 by jenavarr          #+#    #+#             */
/*   Updated: 2024/05/02 02:28:18 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/get_next_line.h"

char	*freeshit(char **buffer)
{
	free(*buffer);
	*buffer = NULL;
	return (NULL);
}

char	*erase_line(char *buffer)
{
	char	*new;
	int		i;
	int		c;

	if (!buffer)
		return (freeshit(&buffer));
	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\0')
		return (freeshit(&buffer));
	c = 0;
	new = ftg_calloc(ft_strlen(buffer) - i + 1);
	if (!new)
		return (freeshit(&buffer));
	i++;
	c = 0;
	while (buffer[i])
		new[c++] = buffer[i++];
	freeshit(&buffer);
	return (new);
}

char	*assert_line(char *buffer, int fd)
{
	char	*tmp;
	int		bytes;

	tmp = (char *)malloc((ssize_t)BUFFER_SIZE + 1);
	if (tmp == NULL)
		return (freeshit(&buffer));
	bytes = 1;
	while (!ftg_strrchr(buffer, '\n', 0) && bytes != 0)
	{
		bytes = read(fd, tmp, BUFFER_SIZE);
		if (bytes < 0)
		{
			freeshit(&buffer);
			return (freeshit(&tmp));
		}
		tmp[bytes] = '\0';
		buffer = ftg_strjoin(buffer, tmp);
		if (!buffer)
			return (freeshit(&tmp));
	}
	freeshit(&tmp);
	return (buffer);
}

char	*read_line(char	*buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = -1;
	while (buffer[++i] != '\0' && buffer[i] != '\n')
		line[i] = buffer[i];
	if (buffer[i] == '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char		*buffer[255];
	char			*line;

	if (fd < 0 || fd > 255 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer[fd])
	{
		buffer[fd] = ftg_calloc(1);
		if (!buffer[fd])
			return (NULL);
	}
	buffer[fd] = assert_line(buffer[fd], fd);
	if (!buffer[fd])
		return (freeshit(&buffer[fd]));
	line = read_line(buffer[fd]);
	if (!line)
		return (freeshit(&buffer[fd]));
	buffer[fd] = erase_line(buffer[fd]);
	if (!buffer[fd])
		freeshit(&buffer[fd]);
	return (line);
}
