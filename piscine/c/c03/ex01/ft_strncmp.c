/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamato-h <mamato-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:53:24 by mamato-h          #+#    #+#             */
/*   Updated: 2023/08/21 17:25:56 by mamato-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
#include <string.h>
*/

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	char				*p1;
	char				*p2;
	unsigned int		cont;

	p1 = s1;
	p2 = s2;
	cont = 0;
	while (*p1 != '\0' && *p2 != '\0' && cont < n)
	{
		if (*p1 > *p2)
			return (1);
		else if (*p1 < *p2)
			return (-1);
		++p1;
		++p2;
		++cont;
	}
	if (*p1 != '\0' && cont < n)
		return (1);
	else if (*p2 != '\0' && cont < n)
		return (-1);
	return (0);
}

/*
int main(){
	int i = ft_strncmp("Hola", "Holaaaa", 10);
	int j = strncmp("Hola", "Holaaaa", 10);
    printf("Mio: %d, No mio: %d", i, j);
}
*/