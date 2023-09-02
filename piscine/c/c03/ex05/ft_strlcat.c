/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamato-h <mamato-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 21:28:48 by mamato-h          #+#    #+#             */
/*   Updated: 2023/08/21 17:19:25 by mamato-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
#include <string.h>
*/

unsigned int	size_str(char *str)
{
	unsigned int	ret;

	ret = 0;
	while (*str != '\0')
	{
		++str;
		++ret;
	}
	return (ret);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	cont;
	unsigned int	size_s;
	unsigned int	size_d;
	char			*cs;

	cont = 0;
	size_d = 0;
	cs = src;
	size_s = size_str(cs);
	while (*dest != '\0')
	{
		++dest;
		++size_d;
	}
	if (size == 0 || size <= size_d)
		return (size_s + size);
	while (*src != '\0' && cont < size - size_d - 1)
	{
		*dest = *cs;
		++dest;
		++cs;
		++cont;
	}
	*dest = '\0';
	return (size_s + size_d);
}
/*
int main()
{
	char src[70] = "xyz";
	char dest[70] = "aaaa";
	char dest2[70] = "aaaa";
	printf("%s %d\n", dest, ft_strlcat(dest, src, 20));
	printf("%s %lu\n", dest2, strlcat(dest2, src, 20));
	return 0;
}
*/