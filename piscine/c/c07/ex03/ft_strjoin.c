/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamato-h <mamato-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 12:09:59 by mamato-h          #+#    #+#             */
/*   Updated: 2023/08/31 01:25:31 by mamato-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	cont;

	cont = 0;
	while (str[cont])
	{
		cont++;
	}
	return (cont);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	cont;

	cont = 0;
	while (*src != '\0')
	{
		*dest = *src;
		++dest;
		++src;
		++cont;
	}
	*dest = '\0';
	dest -= cont;
	return (dest);
}

char	*ft_strcat(char *dest, char *src)
{
	char	*cpy;

	cpy = dest;
	while (*cpy != '\0')
		++cpy;
	while (*src != '\0')
	{
		*cpy = *src;
		++cpy;
		++src;
	}
	*cpy = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (size <= 0)
	{
		ret = malloc(sizeof(char));
		ret = 0;
		return (ret);
	}
	while (i < size)
		j += ft_strlen(strs[i++]);
	ret = malloc((j + ((size - 1) * ft_strlen(sep)) + 1) * sizeof(char));
	i = 0;
	ft_strcpy(ret, strs[i++]);
	while (i < size)
	{
		ret = ft_strcat(ret, sep);
		ret = ft_strcat(ret, strs[i]);
		++i;
	}
	return (ret);
}

/*
#include <stdio.h>
int main(){
	char *si[] = {"", "", ""};
	char *sep = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";

	char *ret = ft_strjoin(7, si, sep);
	printf("%s", ret);
}
*/