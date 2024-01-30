/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelikan <avelikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:27:24 by avelikan          #+#    #+#             */
/*   Updated: 2024/01/23 11:25:08 by avelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <limits.h>
# include <stdint.h>

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 42

# endif

typedef struct struct_buffer
{
	char	*buf;
	size_t	len;
}	t_buffer;

size_t	ft_strchr(const char *buffer, char c, size_t len);
void	set_buffer(t_buffer *buffer, char *buf_buf, size_t buf_len);
void	buf_append(t_buffer *buffer, char *buf_read, ssize_t mem_read);
int		buf_expand(ssize_t mem_read, char *buf_read, t_buffer *buffer);
char	*get_next_line(int fd);

#endif
