/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelikan <avelikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 09:41:38 by avelikan          #+#    #+#             */
/*   Updated: 2024/01/23 11:56:07 by avelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(int ac, char **av)
{
	int		fd;
	char	*line;

	if (ac != 2)
		return (0);
	if ((av[1][0] == '1' && av[1][1] == '\0')
		|| (av[1][0] == '0' && av[1][1] == '\0'))
		fd = 1;
	else
		fd = open(*(av + 1), O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
		else
			printf("%s", line);
	}
	close(fd);
	return (0);
}
