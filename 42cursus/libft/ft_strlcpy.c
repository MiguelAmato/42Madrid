/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amato <amato@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:45:37 by amato             #+#    #+#             */
/*   Updated: 2023/09/05 21:14:07 by amato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	cont;
	char	*dst_c;

	dst_c = dst;
	cont = 0;
	if (size > 0)
	{
		while (*src != '\0' && cont < size - 1)
		{
			*dst_c = *src;
			++dst_c;
			++src;
			++cont;
		}
	}
	*dst_c = '\0';
	while (*src != '\0')
	{
		++cont;
		++src;
	}
	return (cont);
}
