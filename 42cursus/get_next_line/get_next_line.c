/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amato <amato@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:28:13 by amato             #+#    #+#             */
/*   Updated: 2024/01/29 22:11:56 by amato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		++i;
	return (i);
}

char	*ft_strdup(char *s, int *i)
{
	char		*dup;
	size_t		size;

	size = ft_strlen(s + (*i));
	dup = malloc(sizeof(char) * (size + 1));
	if (dup == 0)
		return (0);
	while (s[*i] != '\n' && s[*i] != '\0')
	{
		dup[*i] = s[*i];
		s[*i] = '\n';
		++(*i);
	}
	dup[*i] = '\0';
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
	i = 0;
	while (s2[(*count)] != '\n' && s2[(*count)] != '\0') {
		ret[j++] = s2[(*count)];
		s2[(*count)++] = '\n';
	}
	ret[j] = '\0';
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*ret;
	int			i;
	if (BUFFER_SIZE <= 0)
		return (0);
	i = 0;
	while (buffer[i++] == '\n');
	ret = ft_strdup(buffer, &i);
	if (!ret)
		return (0);
	while (i == BUFFER_SIZE - 1) 
	{
		if (read(fd, buffer, BUFFER_SIZE) == -1)
		{
			free(ret);
			return (0);
		}
		ret = ft_strjoin(ret, buffer, &i);
	}	
	return (ret);
}

int main () {
	return 0;
}