/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamato-h <mamato-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 21:59:18 by mamato-h          #+#    #+#             */
/*   Updated: 2023/08/13 22:02:48 by mamato-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	make_walls(int dim[2], char fst, char mid, char lst)
{
	int	cont;

	cont = 0;
	ft_putchar(fst);
	while (cont < dim[0] - 2)
	{
		ft_putchar(mid);
		++cont;
	}
	if (dim[0] > 1)
		ft_putchar(lst);
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	aux[2];
	int	i;

	aux[0] = x;
	aux[1] = y;
	i = 0;
	if (x > 0 && y > 0)
	{
		make_walls(aux, 'A', 'B', 'C');
		if (x > 0 && y > 1)
		{
			while (i < y - 2)
			{
				make_walls(aux, 'B', ' ', 'B');
				++i;
			}
		}
		if (y > 1)
			make_walls(aux, 'C', 'B', 'A');
	}
}
