/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamato-h <mamato-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:28:13 by amato             #+#    #+#             */
/*   Updated: 2024/02/20 18:04:09 by mamato-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*ret;
	int			i;
	int			nread;

	if (BUFFER_SIZE <= 0 && fd < 0)
		return (0);
	nread = 0;
	ret = ft_strdup(buffer, &i);
	if (ret && buffer[i] != NL)
	{
		nread = read(fd, buffer, BUFFER_SIZE);
		while (nread > 0)
		{
			buffer[nread] = '\0';
			ret = ft_strjoin(ret, buffer, &i);
			if (!ret || buffer[i] == NL)
				break ;
			nread = read(fd, buffer, BUFFER_SIZE);
		}
	}
	if (nread == -1 || (nread == 0 && !ft_strlen(buffer)))
		return (ft_check_leaks(nread, ret, buffer));
	move_buffer(buffer);
	return (ret);
}


// #include <fcntl.h>
// #include <stdio.h>
// #include <sys/stat.h>

// int main () {
// 	// int fd = open("prueba.txt", O_RDONLY);
// 	// char *ret = get_next_line(fd);
// 	// while (ret) {
// 	// 	printf("%s", ret);
// 	// 	ret = get_next_line(fd);
// 	// }
// 	int fd = open("prueba.txt", O_RDWR);
// 	close(fd);
// 	printf("%s\n", get_next_line(1000));
// 	return (0);
// }
