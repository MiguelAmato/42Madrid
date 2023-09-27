/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amato <amato@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 21:23:38 by amato             #+#    #+#             */
/*   Updated: 2023/09/18 11:08:44 by amato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	return ((c >= '\t' && c <= '\r') || c == ' ');
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	n;
	int	neg;

	n = 0;
	i = 0;
	neg = 1;
	while (ft_isspace(nptr[i]))
		++i;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			neg = -1;
		++i;
	}
	while (ft_isdigit(nptr[i]))
	{
		n *= 10;
		n += (nptr[i] - '0');
		++i;
	}
	return (n * neg);
}
