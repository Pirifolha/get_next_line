/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelsousa <miguelsousa@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 20:46:40 by miguelsousa       #+#    #+#             */
/*   Updated: 2025/12/09 20:47:33 by miguelsousa      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
		return (NULL);
	while (s1 && s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		res[i] = s2[j];
		i++;
		if (s2[j] == '\n')
			break ;
		j++;
	}
	res[i] = '\0';
	free(s1);
	return (res);
}

int	has_nl_and_clean(char *buffer)
{
	int	i;
	int	j;
	int	nl;

	i = 0;
	j = 0;
	nl = 0;
	while (buffer[i])
	{
		if (nl == 1)
			buffer[j++] = buffer[i];
		if (buffer[i] == '\n')
			nl = 1;
		buffer[i] = '\0';
		i++;
	}
	return (nl);
}