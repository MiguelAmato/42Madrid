/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamato-h <mamato-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 12:49:34 by mamato-h          #+#    #+#             */
/*   Updated: 2023/08/30 22:25:47 by mamato-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	cont;

	cont = 0;
	while (str[cont])
		cont++;
	return (cont);
}

char	*ft_strdup(char *src)
{
	char	*dup;
	char	*cpy;
	int		size;

	size = 0;
	while (*src)
	{
		++size;
		++src;
	}
	src -= size;
	dup = malloc(sizeof(char) * (size + 1));
	cpy = dup;
	if (dup == 0)
		return (0);
	while (*src)
	{
		*dup = *src;
		++dup;
		++src;
	}
	*dup = '\0';
	return (cpy);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*ret;

	i = 0;
	ret = malloc((ac + 1) * sizeof(t_stock_str));
	if (ret == 0)
		return (0);
	while (i < ac)
	{
		ret[i].size = ft_strlen(av[i]);
		ret[i].str = ft_strdup(av[i]);
		if (ret[i].str == 0)
			return (0);
		ret[i].copy = ft_strdup(ret[i].str);
		if (ret[i].copy == 0)
			return (0);
		++i;
	}
	ret[i].str = 0;
	return (ret);
}
