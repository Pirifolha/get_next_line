/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misousa <misousa@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 18:34:21 by misousa           #+#    #+#             */
/*   Updated: 2025/12/02 17:49:25 by misousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"
#include <fcntl.h>

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			n_bytes;

	
	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	n_bytes = 1;
	while(fd > 0)
	{

	}
	return (0);
}

int	main(void)
{
	int fd;
	char *line;
	fd = open("aa.txt", O_RDONLY);

	line = get_next_line(fd);
	printf("%s\n", line);
	free(line);
}