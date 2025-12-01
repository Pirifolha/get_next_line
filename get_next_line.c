/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelsousa <miguelsousa@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 18:34:21 by misousa           #+#    #+#             */
/*   Updated: 2025/12/01 19:20:46 by miguelsousa      ###   ########.fr       */
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
	int			i;

	n_bytes = 0;
	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		i = 0;
		n_bytes = read(fd, buffer, BUFFER_SIZE);
		printf("%d\n", n_bytes);
		printf("%s\n", line);
		line = ft_strjoin(line, buffer);
		return (line);
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