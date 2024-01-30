/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amato <amato@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:28:13 by amato             #+#    #+#             */
/*   Updated: 2024/01/30 02:46:18 by amato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != NL)
		++i;
	return (i);
}

char	*ft_strdup(char *s, int *i)
{
	char		*dup;
	size_t		size;
	int			j;

	*i = 0;
	size = ft_strlen(s);
	dup = malloc(sizeof(char) * (size + 1));
	if (dup == 0)
		return (0);
	j = 0;
	while (s[*i] != NL && s[*i] != '\0')
	{
		dup[j] = s[*i];
		++(*i);
		++j;
	}
	dup[j] = '\0';
	return (dup);
}

char	*ft_strjoin(char *s1, char *s2, int *count)
{
	char	*ret;
	int		i;
	int		j;

	ret = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!ret)
		return (0);
	i = 0;
	j = 0;
	while (s1[i])
		ret[j++] = s1[i++];
	*count = 0;
	while (s2[*count] != NL && s2[*count] != '\0') {
		ret[j++] = s2[*count];
		(*count)++;
	}
	free(s1);
	ret[j] = '\0';
	return (ret);
}

void move_buffer(char *buffer)
{
	int	i;
	int start;

	i = 0;
	while (buffer[i++] != NL);
	start = 0;
	while (buffer[i])
	{
		buffer[start] = buffer[i];
		buffer[i] = '\0';
		++i;
		++start;
	}
	buffer[start] = '\0';
}


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
	if (nread == -1 || nread == 0)
		return (0);
	move_buffer(buffer);
	return (ret);
}
/*
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
int main () {
	int fd = open("prueba.txt", O_RDONLY);
	char *ret = get_next_line(fd);
	printf("%s\n", ret);
	while (ret) {
		printf("%s\n", ret);
		ret = get_next_line(fd);
	}
	return 0;
}
*/