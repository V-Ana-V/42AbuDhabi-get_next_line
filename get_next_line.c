/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelikan <avelikan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:40:41 by avelikan          #+#    #+#             */
/*   Updated: 2024/01/18 13:40:45 by avelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//Here we add to the buffer additional part that contains new line. Pay attention that we did not free the tail here.
//Check for malloc protections!!!
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
	return(append_tail);
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
	while (buffer[l] != '\n')
		l++;
	line = ft_substr(buffer, 0, l + 1);
	return (line);
}

char	read_line(int fd, char *buffer)
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

}
