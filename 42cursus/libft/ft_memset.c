/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amato <amato@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:53:48 by amato             #+#    #+#             */
/*   Updated: 2023/09/05 21:17:56 by amato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*cpy;
	size_t			i;

	cpy = (unsigned char *)s;
	i = 0;
	while (i < n)
		cpy[i++] = (unsigned char)c;
	return (s);
}
