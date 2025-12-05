/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelsousa <miguelsousa@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 18:33:04 by misousa           #+#    #+#             */
/*   Updated: 2025/12/05 16:27:59 by miguelsousa      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*fill_line(int fd, char *line, char *buffer);
char	*ft_strchr(char *s, int c);
int		ft_strlen(const char *s);
char	*ft_substr(char *s, unsigned int start, unsigned int len);
char	*set_line(char *line);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s);
char	*clean_buffer(char *buffer);
int	check_line(char *line);

#endif