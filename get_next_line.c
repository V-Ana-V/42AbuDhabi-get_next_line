/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelikan <avelikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:40:41 by avelikan          #+#    #+#             */
/*   Updated: 2024/01/20 18:25:47 by avelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*buf_append(char *buffer, char *tail)
{
	char	*append_tail;

	if (!buffer)
	{
		buffer = malloc(1);
		if (!buffer)
			return (NULL);
		*buffer = '\0';
	}
	append_tail = ft_strjoin(buffer, tail);
	free(buffer);
	return (append_tail);
}

char	*buf_update(char *buffer)
{
	char	*tail;

	tail = ft_strdup(ft_strchr(buffer, '\n') + 1);
	free(buffer);
	return (tail);
}

char	*buf_extract(char *buffer)
{
	char	*line;
	int		l;

	l = 0;
	while (buffer[l] != '\n' && buffer[l] != '\0')
		l++;
	if (l == 0)
		return (NULL);
	line = ft_sstr(buffer, l + 1);
	return (line);
}

char	*read_line(int fd, char *buffer)
{
	ssize_t	mem_read;
	char	*buf_read;

	mem_read = 1;
	buf_read = malloc(BUFFER_SIZE + 1);
	if (!buf_read)
		return (NULL);
	while (mem_read > 0)
	{
		mem_read = read(fd, buf_read, BUFFER_SIZE);
		if (mem_read == -1)
		{
			free(buf_read);
			return (NULL);
		}
		buf_read[mem_read] = '\0';
		buffer = buf_append(buffer, buf_read);
		if (ft_strchr(buf_read, '\n') != NULL)
			break ;
	}
	free(buf_read);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_line(fd, buffer);
	if (!buffer)
		return (NULL);
	line = buf_extract(buffer);
	buffer = buf_update(buffer);
	return (line);
}
