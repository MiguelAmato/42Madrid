/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamato-h <mamato-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 13:22:33 by mamato-h          #+#    #+#             */
/*   Updated: 2023/08/31 01:24:32 by mamato-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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
	dup = malloc(sizeof(char) * size);
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

/*
#include <stdio.h>
int main()
{
	char *src = "Hola que tal";
	char *dup = ft_strdup(src);
	printf("%s", dup);
}
*/