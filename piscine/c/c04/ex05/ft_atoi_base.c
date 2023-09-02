/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamato-h <mamato-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:15:36 by mamato-h          #+#    #+#             */
/*   Updated: 2023/08/21 20:55:19 by mamato-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	is_a_member(char *base, char c)
{
	while (*base != '\0')
	{
		if (*base == c)
			return (1);
		++base;
	}
	return (0);
}

char	*ft_atoi(char *str, int *neg)
{
	int		cont;

	cont = 0;
	while (*str == ' ' && *str != '\0')
		++str;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			++cont;
		++str;
	}
	if (cont % 2 != 0)
		*neg = 1;
	return (str);
}

int	check_repetitions(int *n, char *base)
{
	char	*i;
	char	*j;

	i = base;
	j = base;
	while (*i != '\0')
	{
		j = i + 1;
		while (*j != '\0')
		{
			if (*i == *j || *j == '+' || *j == '-')
				return (1);
			if (*j == ' ' && *j == '\t' && *j == '\n')
				return (1);
			if (*j == '\v' && *j == '\f' && *j == '\r')
				return (1);
			++j;
		}
		++i;
		++(*n);
	}
	return (0);
}

int	change_base(char *str, char *base, int size)
{
	int	ret;
	int	aux;
	int	base_size;
	int	i;
	int	j;

	ret = 0;
	i = 0;
	base_size = 0;
	aux = 1;
	while (*(base++) != '\0')
		++base_size;
	j = size - i - 1;
	while (i++ < size)
	{
		aux = 1;
		while (j-- > 0)
			aux = base_size * aux;
		ret += (aux * (*str - '0'));
		++str;
	}
	return (ret);
}

int	ft_atoi_base(char *str, char *base)
{
	int		n;
	int		ret;
	char	*cpy;
	char	*cha;
	int		neg;

	n = 0;
	neg = 0;
	ret = check_repetitions(&n, base);
	if (n > 1 && !ret)
	{
		cpy = ft_atoi(str, &neg);
		cha = cpy;
		n = 0;
		while (*(cpy++) != '\0' && is_a_member(base, *cpy))
			++n;
		ret = change_base(cha, base, n);
		if (neg)
			return (ret * -1);
		else
			return (ret);
	}
	return (0);
}
