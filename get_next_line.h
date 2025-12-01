/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelsousa <miguelsousa@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 18:33:04 by misousa           #+#    #+#             */
/*   Updated: 2025/11/24 20:47:43 by miguelsousa      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

#include <unistd.h>
# include <stdlib.h>
#include "stdio.h"
#include <fcntl.h>

char	*get_next_line(int fd);
char	*fill_line(int fd, char *line, char *buffer);
char	*ft_strchr(char *s, int c);
int	ft_strlen(const char *s);
char	*ft_substr(char *s, unsigned int start, unsigned int len);
char	*set_line(char *line);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s);

#endif