/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamato-h <mamato-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 13:34:24 by mamato-h          #+#    #+#             */
/*   Updated: 2023/08/17 12:00:58 by mamato-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdint.h>

#define MAX 16

const static char	g_hex[] = {'0', '1', '2', '3', '4', '5', '6',
	'7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

void	print_fst_dir(intptr_t addr)
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
	write(1, ":", 1);
}

void	hex_c(char *str, unsigned int cont, int line, unsigned int size)
{
	int	spaces;

	spaces = 0;
	while (line < MAX && cont < size)
	{
		if (line % 2 == 0)
		{
			write(1, " ", 1);
			++spaces;
		}
		write(1, &g_hex[(unsigned char)*str / 16], 1);
		write(1, &g_hex[(unsigned char)*str % 16], 1);
		++str;
		++line;
		++(cont);
		spaces += 2;
	}
	while (spaces < 40)
	{
		write(1, " ", 1);
		++spaces;
	}
}

void	print_str(char *str, unsigned int *cont, int *line, unsigned int size)
{
	write(1, " ", 1);
	while (*line < MAX && *cont < size)
	{
		if (*str >= ' ' && *str <= '~')
			write(1, str, 1);
		else
			write(1, ".", 1);
		++(*cont);
		++(*line);
		++str;
	}
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	cont;
	char			*cpy;
	int				line;
	intptr_t		dir;

	cpy = (char *)addr;
	cont = 0;
	while (cont < size)
	{
		line = 0;
		dir = (intptr_t)cpy;
		print_fst_dir(dir);
		hex_c(cpy, cont, line, size);
		print_str(cpy, &cont, &line, size);
		cpy += line;
	}
	return (addr);
}
