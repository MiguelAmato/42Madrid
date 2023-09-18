/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amato <amato@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:11:32 by amato             #+#    #+#             */
/*   Updated: 2023/09/18 11:07:16 by amato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size_num(int n)
{
	int	cont;

	cont = 1;
	while (n > 9)
	{
		n /= 10;
		++cont;
	}
	return (cont);
}

static void	ft_strrev(char *str)
{
	int	size;
	int	i;
	int	j;
	int	aux;

	size = ft_strlen(str);
	i = 0;
	j = size - 1;
	while (i < size / 2)
	{
		aux = str[i];
		str[i] = str[j];
		str[j] = aux;
		++i;
		--j;
	}
}

void	abs_aux(int *neg, int *n)
{
	*neg = 0;
	if (*n < 0)
	{
		*neg = 1;
		*n = -(*n);
	}
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		neg;
	int		i;

	if (n == -2147483648)
	{
		ret = ft_strdup("-2147483648");
		return (ret);
	}
	abs_aux(&neg, &n);
	ret = malloc((ft_size_num(n) + neg + 1) * sizeof(char));
	if (!ret)
		return (0);
	i = 0;
	while (n > 9)
	{
		ret[i++] = (n % 10) + '0';
		n /= 10;
	}
	ret[i++] = n + '0';
	if (neg)
		ret[i++] = '-';
	ret[i] = '\0';
	ft_strrev(ret);
	return (ret);
}
