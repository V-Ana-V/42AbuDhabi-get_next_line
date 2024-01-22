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
		buffer[0] = '\0';
	}
	append_tail = ft_strjoin(buffer, tail);
	free(buffer);
	return (append_tail);
}

char	*buf_update(char *buffer)
{
	char	*tail;
	char	*endl;

	endl = ft_strchr(buffer, '\n');
	if (endl == NULL)
	{
		free(buffer);
		return (NULL);
	}
	tail = ft_strdup(endl + 1);
	free(buffer);
	return (tail);
}

char	*buf_extract(char *buffer)
{
	char	*nl;
	char	*endstr;
	char	*line;
	size_t	i;

	nl = ft_strchr(buffer, '\n');
	endstr = ft_strchr(buffer, '\0');
	if (buffer == endstr)
		return (NULL);
	else if (nl == NULL && buffer != endstr)
		return (ft_strdup(buffer));
	line = malloc(nl - buffer + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (i < ((size_t)(nl - buffer) + 1))
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*read_line(int fd, char *buffer)
{
	ssize_t	mem_read;
	char	*buf_read;

	buf_read = calloc(BUFFER_SIZE + 1, 1);
	if (!buf_read)
		return (NULL);
	mem_read = 1;
	while (mem_read > 0)
	{
		mem_read = read(fd, buf_read, BUFFER_SIZE);
		if (mem_read == -1)
		{
			free(buf_read);
			return (NULL);
		}
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

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > ((ssize_t)(SIZE_MAX / 2)))
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = read_line(fd, buffer);
	if (!buffer)
		return (NULL);
	line = buf_extract(buffer);
	buffer = buf_update(buffer);
	return (line);
}

//compile: cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c