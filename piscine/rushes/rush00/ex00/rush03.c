/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamato-h <mamato-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 09:31:21 by carbelae          #+#    #+#             */
/*   Updated: 2023/08/13 21:46:31 by mamato-h         ###   ########.fr       */
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
			make_walls(aux, 'A', 'B', 'C');
	}
}

/*
ANTIGUO RUSH

void	up_down_wall(int x, int y)
{
	char	c;
	int		cont;

	if (x > 0 && y > 0)
	{
		c = 'A';
		cont = 1;
		ft_putchar(c);
		++c;
		while (cont < x - 1)
		{
			ft_putchar(c); 
			++cont;
		}
		if (x > 1)
		{
			++c;
			ft_putchar(c);
		}
		ft_putchar('\n');
	}
}

void	side_walls(int x, int y)
{
	int	cont_x;
	int	cont_y;

	if (x > 0 && y > 1)
	{
		cont_x = 0;
		cont_y = 0;
		while (cont_y < y - 2)
		{
			ft_putchar('B');
			while (cont_x < x - 2)
			{
				ft_putchar(' ');
				++cont_x;
			}
			if (x > 1)
				ft_putchar('B');
			++cont_y;
			cont_x = 0;
			ft_putchar('\n');
		}
	}
}

void	rush(int x, int y)
{
	up_down_wall(x, y);
	side_walls(x, y);
	if (y > 1)
		up_down_wall(x, y);
}
*/