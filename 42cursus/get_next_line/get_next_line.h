/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamato-h <mamato-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:28:09 by amato             #+#    #+#             */
/*   Updated: 2024/02/20 18:01:30 by mamato-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define NL '\n'
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000000
# endif

// get_nex_line.c
char	*get_next_line(int fd);

// get_next_line_utils.c

size_t	ft_strlen(const char *s);

char	*ft_strdup(char *s, int *i);

char	*ft_strjoin(char *s1, char *s2, int *count);

void	move_buffer(char *buffer);

char	*ft_check_leaks(int nread, char *ret, char *buffer);

#endif
