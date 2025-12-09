/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelsousa <miguelsousa@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 15:54:48 by miguelsousa       #+#    #+#             */
/*   Updated: 2025/12/09 20:18:46 by miguelsousa      ###   ########.fr       */
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
		return (has_nl_and_clean(buffer), NULL);
	while (1)
	{
		if (buffer[0] == '\0')
		{
			n_bytes = read(fd, buffer, BUFFER_SIZE);
			if (n_bytes < 0)
				return (has_nl_and_clean(buffer), free(line), NULL);
			else if (n_bytes == 0)
				break ;
		}
		line = ft_strjoin(line, buffer);
		if (has_nl_and_clean(buffer))
			break ;
	}
	return (line);
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