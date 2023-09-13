/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamato-h <mamato-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:24:28 by mamato-h          #+#    #+#             */
/*   Updated: 2023/09/13 17:30:47 by mamato-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	int		i;

	ret = malloc((len - start + 2) * sizeof(char));
	if (!ret)
		return (0);
	i = 0;
	while (start <= len)
		ret[i++] = s[start++];
	return (ret);
}
