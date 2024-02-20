/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamato-h <mamato-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:11:26 by mamato-h          #+#    #+#             */
/*   Updated: 2024/02/20 18:43:08 by mamato-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i] != '\0' && s[i] != NL)
		++i;
	if (s[i] == NL)
		++i;
	return (i);
}

char	*ft_strdup(char *s, int *i)
{
	char	*dup;
	size_t	size;
	int		j;

	*i = 0;
	dup = NULL;
	size = ft_strlen(s);
	if (size == -1)
		return (0);
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
	if (s[*i] == NL)
		dup[j++] = '\n';
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
	{
		free(s1);
		return (0);
	}
	i = 0;
	j = 0;
	while (s1[i])
		ret[j++] = s1[i++];
	*count = 0;
	while (s2[*count] != NL && s2[*count] != '\0')
	{
		ret[j++] = s2[*count];
		(*count)++;
	}
	free(s1);
	if (s2[*count] == NL)
		ret[j++] = '\n';
	ret[j] = '\0';
	return (ret);
}

void	move_buffer(char *buffer)
{
	int	i;
	int	start;

	i = 0;
	while (buffer[i] != NL && buffer[i])
		++i;
	if (buffer[i] == NL)
		++i;
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

char	*ft_check_leaks(int nread, char *ret, char *buffer)
{
	int	i;

	i = 0;
	if (nread == -1)
	{
		while (buffer[i])
			buffer[i++] = '\0';
	}
	if (ret)
		free(ret);
	return (0);
}
