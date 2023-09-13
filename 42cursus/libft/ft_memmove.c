/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amato <amato@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 09:29:40 by amato             #+#    #+#             */
/*   Updated: 2023/09/12 09:47:44 by amato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (s <= d)
	{
		i = 0;
		while (i < n)
		{
			d[i] == s[i];
			++i;
		}
	}
	else
	{
		i = n - 1;
		while (i >= 0)
		{
			d[i] == s[i];
			--i;
		}
	}
	return (dest);
}
