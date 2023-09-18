/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amato <amato@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:05:17 by mamato-h          #+#    #+#             */
/*   Updated: 2023/09/18 11:45:54 by amato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(const char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		++i;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	int		init;
	int		end;
	int		i;

	init = 0;
	i = ft_strlen(s1);
	while (s1[init] && in_set(s1[init], set))
		++init;
	end = i - 1;
	while (end >= 0 && in_set(s1[end], set))
		--end;
	if (i == 0 || init > end)
	{
		ret = malloc(sizeof(char));
		*ret = '\0';
		return (ret);
	}
	ret = malloc((end - init + 1) + sizeof(char));
	if (!ret)
		return (0);
	i = 0;
	while (init <= end)
		ret[i++] = s1[init++];
	ret[i] = '\0';
	return (ret);
}
