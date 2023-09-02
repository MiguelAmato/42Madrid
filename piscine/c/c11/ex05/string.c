/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamato-h <mamato-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 04:23:24 by mamato-h          #+#    #+#             */
/*   Updated: 2023/08/31 04:24:31 by mamato-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_strlen(char *str)
{
	int	cont;

	cont = 0;
	while (str[cont])
		++cont;
	return (cont);
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		++str;
	}
}

void	aux(char *str, int *num)
{
	while (*str >= '0' && *str <= '9')
	{
		if (num != 0)
			(*num) *= 10;
		*num = *num + (*str - '0');
		++str;
	}
}

int	is_space(char c)
{
	return (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ');
}

int	ft_atoi(char *str)
{
	int	ret;
	int	cont;
	int	neg;
	int	num;

	neg = 0;
	ret = 0;
	cont = 0;
	num = 0;
	while (is_space(*str) && *str != '\0')
		++str;
	while ((*str == '+' || *str == '-') && *str != '\0')
	{
		if (*str == '-')
			++cont;
		++str;
	}
	if (cont % 2 != 0)
		neg = 1;
	aux(str, &num);
	if (neg)
		return (num * (-1));
	return (num);
}
