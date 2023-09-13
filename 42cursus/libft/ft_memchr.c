/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amato <amato@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 09:23:03 by amato             #+#    #+#             */
/*   Updated: 2023/09/12 09:23:21 by amato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int i;
	unsigned char	*cpy;

	cpy = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (cpy[i] == c)
			return (s + i);
		++i;
	}
	return (0);
}
