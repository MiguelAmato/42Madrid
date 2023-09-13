/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amato <amato@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 09:24:31 by amato             #+#    #+#             */
/*   Updated: 2023/09/12 09:25:11 by amato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *cpy1;
	unsigned char *cpy2;
	int i;

	if (n == 0)
		return (0);
	i = 0;
	cpy1 = (unsigned char *)s1;
	cpy2 = (unsigned char *)s2;
	while (i < n && cpy1[i] && cpy2[i])
	{
		if (cpy1[i] != cpy2[i])
			break ;
		++i;
	}
	return (cpy1[i] - cpy2[i]);
}
