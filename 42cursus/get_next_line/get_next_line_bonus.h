/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamato-h <mamato-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:12:00 by mamato-h          #+#    #+#             */
/*   Updated: 2024/02/20 12:21:18 by mamato-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# define NL '\n'
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# ifndef MAX_FD
#  define MAX_FD 1024
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
