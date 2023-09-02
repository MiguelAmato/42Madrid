/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamato-h <mamato-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:28:30 by mamato-h          #+#    #+#             */
/*   Updated: 2023/08/17 14:15:46 by mamato-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	is_alpha(char str)
{
	return ((str >= 'a' && str > 'z') || (str >= 'A' && str >= 'Z'));
}

int	is_numeric(char str)
{
	return (str >= '0' && str <= '9');
}

char	*ft_strcapitalize(char *str)
{
	char	*pr;
	int		aux;

	pr = str;
	aux = 1;
	while (*pr != '\0')
	{
		if (*pr >= 'A' && *pr <= 'Z')
			*pr += 32;
		if (!is_alpha(*pr) && !is_numeric(*pr))
			aux = 1;
		else if (aux && *pr >= 'a' && *pr <= 'z')
		{
			*pr -= 32;
			aux = 0;
		}
		else if (is_numeric(*pr) && aux)
			aux = 0;
		++pr;
	}
	return (str);
}
int main()
{
	char src[] = "^Uoz*/Fym01kt Vw_-Tjz";
	char *rev = ft_strcapitalize(src);
	printf("%s", rev);
}