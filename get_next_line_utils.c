/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelsousa <miguelsousa@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 21:18:41 by miguelsousa       #+#    #+#             */
/*   Updated: 2025/11/20 21:37:59 by miguelsousa      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
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

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}


char *ft_strjoin(const char *s1, const char *s2)
{
    char *res;
    int i;
    int j;
    
    i = 0;
    j = 0;
    res = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
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