/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamato-h <mamato-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 21:28:24 by mamato-h          #+#    #+#             */
/*   Updated: 2023/08/21 16:48:53 by mamato-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

char	*aux(int *cont, char *str, char *to_find)
{
	while (*str != '\0')
	{
		if (*str == *to_find)
		{
			++to_find;
			++(*cont);
			++str;
			if (*to_find == '\0')
				return (str - (*cont));
		}
		else
		{
			++str;
			str -= *cont;
			to_find -= *cont;
			*cont = 0;
		}
	}
	return (str);
}

char	*ft_strstr(char *str, char *to_find)
{
	int		cont;
	char	*cpy;
	char	*p;

	if (*to_find != '\0')
	{
		cpy = str;
		cont = 0;
		p = aux(&cont, str, to_find);
		if (*p == '\0')
			return (0);
		return (p);
	}
	return (str);
}

/*
int main()
{
	char uno[] = "123422222";
    char dos[] = "1234";
    char *ret = ft_strstr(uno, dos);
    printf("%s", ret);
}
*/
