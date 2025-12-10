/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misousa <misousa@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 20:46:44 by miguelsousa       #+#    #+#             */
/*   Updated: 2025/12/10 16:08:55 by misousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			n_bytes;

	line = NULL;
	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE <= 0)
		return (has_nl_and_clean(buffer[fd]), NULL);
	while (1)
	{
		if (buffer[fd][0] == '\0')
		{
			n_bytes = read(fd, buffer[fd], BUFFER_SIZE);
			if (n_bytes < 0)
				return (has_nl_and_clean(buffer[fd]), free(line), NULL);
			else if (n_bytes == 0)
				break ;
		}
		line = ft_strjoin(line, buffer[fd]);
		if (has_nl_and_clean(buffer[fd]) == 1)
			return (line);
	}
	return (line);
}
/* int	main(void)
{
	char *line;
	int i;

	int fd1 = open("aa.txt", O_RDONLY);
	int fd2 = open("aa2.txt", O_RDONLY);
	int fd3 = open("aa3.txt", O_RDONLY);
	i = 0;

	while (i < 5)
	{
		line = get_next_line(fd1);
		printf("%s", line);
		free(line);
		i++;
	}
	
	i = 0;
	while (i < 5)
	{
		line = get_next_line(fd2);
		printf("%s", line);
		free(line);
		i++;
	}
	
	i = 0;

	while (i < 5)
	{
		line = get_next_line(fd3);
		printf("%s", line);
		free(line);
		i++;
	}
} */