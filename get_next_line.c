/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misousa <misousa@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 18:34:21 by misousa           #+#    #+#             */
/*   Updated: 2025/11/21 19:30:50 by misousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"
# include <fcntl.h>

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	int			n_bytes;
	char		*res;

	n_bytes = 0;
	res = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		n_bytes = read(fd, buffer, BUFFER_SIZE);
		if (n_bytes == 0)
		{
			res = ft_strjoin(res, buffer);
			return (res);
		}
	}
	// if (ft_strchr(buffer, '\n') != 0)
	//	return (buffer);
}

int	main(void)
{
	int fd;
	char *line;
	fd = open("get_next_line.c", O_RDONLY);

	line = get_next_line(fd);
	printf("%s\n", line);
	free(line);
}