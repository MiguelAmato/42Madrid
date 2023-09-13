/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamato-h <mamato-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:45:37 by amato             #+#    #+#             */
/*   Updated: 2023/09/13 20:35:46 by mamato-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	cont;
	char	*dst_c;

	dst_c = dst;
	cont = 0;
	if (dstsize > 0)
	{
		while (*src != '\0' && cont < dstsize - 1)
		{
			*dst_c = *src;
			++dst_c;
			++src;
			++cont;
		}
		*dst_c = '\0';
	}
	while (*src != '\0')
	{
		++cont;
		++src;
	}
	return (cont);
}
