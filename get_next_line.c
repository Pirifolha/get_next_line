/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelsousa <miguelsousa@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 18:34:21 by misousa           #+#    #+#             */
/*   Updated: 2025/11/20 21:18:54 by miguelsousa      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    static size_t BUFFER_SIZE;
    char *buffer;
    int count;

    buffer = malloc(BUFFER_SIZE * sizeof(char));
    
    
}