/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamato-h <mamato-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:38:07 by mamato-h          #+#    #+#             */
/*   Updated: 2023/08/17 11:59:31 by mamato-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

const static char	g_hex[] = {'0', '1', '2', '3', '4', '5', '6',
	'7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

void	print_hex_value(char c)
{
	write(1, "\\", 1);
	write(1, &g_hex[(unsigned char)c / 16], 1);
	write(1, &g_hex[(unsigned char)c % 16], 1);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str != '\0')
	{
		if (*str < 32 || *str > 126)
			print_hex_value(*str);
		else
			write(1, str, 1);
		++str;
	}
}
