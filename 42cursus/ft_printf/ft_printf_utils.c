/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamato-h <mamato-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 19:44:44 by mamato-h          #+#    #+#             */
/*   Updated: 2023/09/29 17:54:53 by mamato-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_memory_dir(intptr_t addr)
{
	char	aux[MAX];
	int		cont;

	cont = MAX - 1;
	while (cont >= 0 && addr >= MAX)
	{
		aux[cont] = (char)g_hex[addr % MAX];
		addr /= MAX;
		--cont;
	}
	while (cont >= 0)
	{
		aux[cont] = '0';
		--cont;
	}
	cont = 0;
	while (cont < MAX)
	{
		write(1, &aux[cont], 1);
		++cont;
	}
	return (0);
}
