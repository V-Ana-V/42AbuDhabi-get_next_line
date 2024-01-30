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
#include "get_next_line_bonus.h"

//This main is for checking bonus part:
int	main(int ac, char **av)
{
	int		fd1;
	int		fd2;
	char	*line;

	if (ac != 3)
		return (0);
	fd1 = open(*(av + 1), O_RDONLY);
	fd2 = open(*(av + 2), O_RDONLY);
	line = "asdjo";
	//The shortest file should be first among arguments!
	while (line != NULL)
	{
		line = get_next_line(fd1);
		printf("line[1] %s", line);
		free(line);
		line = get_next_line(fd2);
		printf("line[2] %s", line);
		free(line);
	}
	if (line)
		free(line);
	close(fd1);
	close(fd2);
	return (0);
}
