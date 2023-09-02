/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamato-h <mamato-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:46:09 by mamato-h          #+#    #+#             */
/*   Updated: 2023/08/31 18:03:11 by mamato-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str, char *sep, int pos)
{
	int	cont;
	int	i;

	cont = 0;
	while (str[pos] != 0)
	{
		i = 0;
		while (sep[i] && sep[i] != str[pos])
			++i;
		if (sep[i] == str[pos])
			break ;
		++cont;
		++pos;
	}
	return (cont);
}

char	*ft_strdup(char *src)
{
	char	*dup;
	char	*cpy;
	int		size;

	size = 0;
	while (*src)
	{
		++size;
		++src;
	}
	src -= size;
	dup = malloc(sizeof(char) * (size + 1));
	cpy = dup;
	if (dup == 0)
		return (0);
	while (*src)
	{
		*dup = *src;
		++dup;
		++src;
	}
	*dup = '\0';
	return (cpy);
}

int	count_separators(char *str, char *sep, int pos)
{
	int	i;
	int	ret;

	ret = 0;
	i = 0;
	while (str[pos] != 0)
	{
		i = 0;
		while (sep[i] && sep[i] != str[pos])
			++i;
		if (sep[i] == str[pos])
			++ret;
		if (sep[i] == '\0' && !ret)
			return (0);
		else if (sep[i] == '\0')
			return (ret);
		++pos;
	}
	if (str[pos] == 0 && ret == 0)
		return (0);
	return (ret);
}

void	ft_split_aux(char *str, char *charset, char **ret, int pos)
{
	char	*word;
	int		aux;
	int		i;

	i = 0;
	while (str[pos] != 0)
	{
		if (count_separators(str, charset, pos) == 0)
		{
			aux = ft_strlen(str, charset, pos);
			word = malloc((ft_strlen(str, charset, pos) + 1) * sizeof(char));
			if (word == 0)
				return ;
			while (str[pos] != 0 && count_separators(str, charset, pos) == 0)
				*word++ = str[pos++];
			*word = '\0';
			word -= aux;
		}
		aux = count_separators(str, charset, pos);
		if (aux != 0 || str[pos] == '\0')
		{
			ret[i++] = ft_strdup(word);
			pos += aux;
		}
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**ret;
	int		words;
	int		pos;
	int		aux;

	pos = count_separators(str, charset, 0);
	words = 0;
	while (str[pos] != 0)
	{
		pos += ft_strlen(str, charset, pos);
		aux = count_separators(str, charset, pos);
		if (aux != 0 || str[pos] == '\0')
		{
			++words;
			pos += aux;
		}
	}
	ret = malloc((words + 1) * sizeof(char *));
	if (ret == 0)
		return (ret);
	pos = count_separators(str, charset, 0);
	ft_split_aux(str, charset, ret, pos);
	ret[words] = 0;
	return (ret);
}

/*
#include <stdio.h>
int main()
{
	char **ret = ft_split(".hola buenas;. . . ; que tal; yo. bien.", ";.");
	for (int i = 0; i < 7; ++i)
		printf("%s\n", ret[i]);
}
*/