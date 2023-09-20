/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamato-h <mamato-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:08:14 by mamato-h          #+#    #+#             */
/*   Updated: 2023/09/20 19:18:48 by mamato-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	sep;
	int	i;

	sep = 1;
	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			sep = 1;
		else if (sep)
		{
			++count;
			sep = 0;
		}
		++i;
	}
	return (count);
}

static int	word_size(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s && *s != c)
	{
		++count;
		++s;
	}
	return (count);
}

int		ft_malloc(char **ret, int count, char const *s, char c)
{
	int	i;

	i = 0;
	ret[count] = malloc((word_size(s, c) + 1) * sizeof(char));
	if (!ret[count])
	{
		while (ret[i])
		{
			free(ret[i]);
			++i;
		}
		free(ret);
		return (1);
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	int		size;
	int		j;
	int		count;

	size = count_words(s, c);
	ret = malloc((size + 1) * sizeof(char *));
	if (!ret)
		return (0);
	count = 0;
	while (count < size)
	{
		j = 0;
		while (*s && *s == c)
			++s;
		if (ft_malloc(ret, count, s, c))
			return (0);
		while (*s && *s != c){
			ret[count][j++] = *s;
			++s;
		}
		ret[count++][j] = '\0';
	}
	ret[size] = 0;
	return (ret);
}


