/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamato-h <mamato-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:08:14 by mamato-h          #+#    #+#             */
/*   Updated: 2023/09/13 16:59:15 by mamato-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	sep;
	int	i;

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

static int	word_size(char const *s, char c, int i)
{
	int	count;

	count = 0;
	while (s[i] && s[i] != c)
	{
		++count;
		++i;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	int		size;
	int		i;
	int		j;
	int		count;

	size = count_words(s, c);
	ret = malloc((size + 1) * sizeof(char));
	i = 0;
	while (s[i] && s[i] == c)
		++i;
	count = 0;
	while (s[i] && count < size)
	{
		ret[count] = malloc((word_size(s, c, i) + 1) * sizeof(char));
		j = 0;
		while (s[i] && s[i] != c)
			ret[count][j++] = s[i++];
		ret[count][j] = '\0';
		while (s[i] && s[i] == c)
			++i;
		++count;
	}
	ret[count] = 0;
	return (ret);
}
