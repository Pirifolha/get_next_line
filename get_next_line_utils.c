/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misousa <misousa@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 21:18:41 by miguelsousa       #+#    #+#             */
/*   Updated: 2025/12/02 17:48:29 by misousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	char	ch;

	ch = c;
	while (*s != ch)
	{
		if (*s == '\0')
			return (0);
		s++;
	}
	return ((char *)s);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0' || s[i] != '\n')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (s1[i])
		res[j++] = s1[i++];
	i = 0;
	while (s2[i])
		res[j++] = s2[i];
	res[j] = 0;
	
	return (res);
}

char	*ft_strdup(char *s)
{
	char	*dest;
	int		i;

	i = 0;
	printf("malloc success");
	dest = malloc(ft_strlen(s) + 1);
	if (dest == 0)
		return (0);
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*fill_line(int fd, char *line, char *buffer)
{
	int	i;

	while (1)
	{
		i = 0;
		read(fd, buffer, BUFFER_SIZE);
		if (line[i] == '\0')
			line = ft_strdup(buffer);
		else
			line = ft_strjoin(line, buffer);
		while (line[i] != '\0' || line[i] != '\n')
		{
			i++;
		}
		if (line[i] != '\0' || line[i] != '\n')
			return (line);
	}
}
char	*ft_substr(char *s, unsigned int start, unsigned int len)
{
	unsigned int	i;
	char			*result;
	unsigned int	slen;

	i = 0;
	slen = ft_strlen(s);
	if (!s)
		return (NULL);
	if (start >= slen)
		len = 0;
	if (len > slen - start)
		len = slen - start;
	result = malloc(len + 1);
	if (!result)
		return (0);
	while (i < len)
	{
		result[i] = s[start];
		start++;
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*set_line(char *line)
{
	int		i;
	char	*new_line;

	i = ft_strlen(line);
	new_line = ft_substr(line, 0, i);
	return (new_line);
}

