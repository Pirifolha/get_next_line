/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelsousa <miguelsousa@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 18:34:21 by misousa           #+#    #+#             */
/*   Updated: 2025/12/05 16:29:33 by miguelsousa      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			n_bytes;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[BUFFER_SIZE] = '\0';
	n_bytes = 1;
	while (n_bytes > 0)
	{
		n_bytes = read(fd, buffer, BUFFER_SIZE);
		if (line == NULL)
			line = ft_strdup(buffer);
		else
			line = ft_strjoin(line, buffer);
		if (ft_strchr(line, '\n') != 0)
			break ;
		line = set_line(line);
	}
	clean_buffer(buffer);
	return (line);
}

int	main(void)
{
	int fd;
	char *line;
	int i = 0;
	fd = open("aa.txt", O_RDONLY);

	while (i < 3)
	{
		line = get_next_line(fd);
		printf("%s\n", line);
		i++;
	}
}