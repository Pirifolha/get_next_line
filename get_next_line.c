/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelsousa <miguelsousa@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 15:54:48 by miguelsousa       #+#    #+#             */
/*   Updated: 2025/12/09 12:56:02 by miguelsousa      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	has_newline(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*set_line(char *line)
{
	int		i;
	char	*new_line;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	new_line = ft_substr(line, 0, i);
	free(line);
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			n_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	while (1)
	{
		if (buffer[0] == '\0')
		{
			n_bytes = read(fd, buffer, BUFFER_SIZE);
			if (n_bytes < 0)
				return (buffer[0] = '\0', free(line), NULL);
			if (n_bytes == 0)
				return (line);
			buffer[n_bytes] = '\0';
		}
		line = ft_strjoin(line, buffer);
		if (!line)
			return (NULL);
		if (has_newline(line))
			return (line = set_line(line), clean_buffer(buffer), line);
		buffer[0] = '\0';
	}
}
/* int	main(void)
{
	int fd;
	char *line;
	int i;

	fd = open("aa.txt", O_RDONLY);
	i = 0;

	while (i < 6)
	{
		line = get_next_line(fd);
		printf("%s", line);
		i++;
	}
} */