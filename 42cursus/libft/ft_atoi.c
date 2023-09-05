/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amato <amato@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 21:23:38 by amato             #+#    #+#             */
/*   Updated: 2023/09/05 21:34:12 by amato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	n;
	int	neg;

	n = 0;
	i = 0;
	while (nptr[i] == ' ' || nptr[i] == '\t')
		++i;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			neg = 1;
		++i;
	}
	while (ft_isdigit(nptr[i]))
	{
		n *= 10;
		n += (nptr[i] - '0');
		++i;
	}
	if (neg)
		n = -n;
	return (n);
}
