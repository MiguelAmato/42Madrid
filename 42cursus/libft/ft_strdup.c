/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amato <amato@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 21:19:47 by amato             #+#    #+#             */
/*   Updated: 2024/01/29 21:08:39 by amato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char		*dup;
	char		*cpy;
	size_t		size;

	size = ft_strlen(s);
	dup = malloc(sizeof(char) * size + 1);
	cpy = dup;
	if (dup == 0)
		return (0);
	while (*s)
	{
		*dup = *s;
		++dup;
		++s;
	}
	*dup = '\0';
	return (cpy);
}
