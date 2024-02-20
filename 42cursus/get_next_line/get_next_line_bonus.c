/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamato-h <mamato-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:08:55 by mamato-h          #+#    #+#             */
/*   Updated: 2024/02/20 18:44:01 by mamato-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 1024

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[MAX_FD][BUFFER_SIZE + 1];
	char		*ret;
	int			i;
	int			nread;

	if (BUFFER_SIZE <= 0 && fd < 0)
		return (0);
	nread = 0;
	ret = ft_strdup(buffer[fd], &i);
	if (ret && buffer[fd][i] != NL)
	{
		nread = read(fd, buffer[fd], BUFFER_SIZE);
		while (nread > 0)
		{
			buffer[fd][nread] = '\0';
			ret = ft_strjoin(ret, buffer[fd], &i);
			if (!ret || buffer[fd][i] == NL)
				break ;
			nread = read(fd, buffer[fd], BUFFER_SIZE);
		}
	}
	if (nread == -1 || (nread == 0 && !ft_strlen(buffer[fd])))
		return (ft_check_leaks(nread, ret, buffer[fd]));
	move_buffer(buffer[fd]);
	return (ret);
}
/*
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>

int main () {
	int a = ft_strlen(NULL);
	return 0;
	// int fd = open("prueba.txt", O_RDONLY);
	// char *ret = get_next_line(fd);
	// while (ret) {
	// 	printf("%s", ret);
	// 	ret = get_next_line(fd);
	// }
	// int fd = open("prueba.txt", O_RDWR);
	// close(fd);
	// printf("%s\n", get_next_line(-1));
	// return (0);
}*/