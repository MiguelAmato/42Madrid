/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamato-h <mamato-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 09:27:26 by amato             #+#    #+#             */
/*   Updated: 2023/09/13 16:42:03 by mamato-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	int		cont;

	if (!little)
		return ((char *)big);
	i = 0;
	cont = 0;
	while (i < len && big[i])
	{
		if (big[i] == little[cont])
		{
			cont++;
			if (!little[cont])
				return ((char *)big + i - cont + 1);
		}
		else
			cont = 0;
		i++;
	}
	return (0);
}
