/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amato <amato@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 09:43:32 by amato             #+#    #+#             */
/*   Updated: 2023/09/12 09:56:12 by amato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t src_size;
	size_t dst_size;

	if (size > 0)
	{
		dst_size = 0;
		src_size = 0;
		while (dst[dst_size] && dst_size < size)
			++dst_size;
		while (src[src_size] && src_size + dst_size < size - 1)
		{
			dst[src_size + dst_size] = src[src_size];
			++src_size;
		}
		if (src_size + dst_size < size)
			dst[src_size + dst_size] = '\0';
	}
	while (src[src_size])
		++src_size;
	return src_size + dst_size;
}
