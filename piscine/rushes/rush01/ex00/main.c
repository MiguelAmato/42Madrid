/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamato-h <mamato-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 14:37:11 by mamato-h          #+#    #+#             */
/*   Updated: 2023/08/20 18:17:00 by bquilumb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#define N 4
#define MAX 16

int	solve(const int tab[N][N], int sol[N][N]);

void	print_solution(int sol[N][N])
{
	char	c;
	int		i;
	int		j;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			c = sol[i][j] + '0';
			write(1, &c, 1);
			if (j < N - 1)
				write(1, " ", 1);
			++j;
		}
		write(1, "\n", 1);
		++i;
	}
}

int	count_numbers(char *str)
{
	int	count;
	int	spaces;

	count = 0;
	spaces = 1;
	while (*str != '\0')
	{
		if ((*str >= '1' && *str <= '4') || *str == ' ')
		{
			if (*str == ' ')
				spaces = 1;
			else if (spaces)
			{
				++count;
				spaces = 0;
			}
			++str;
		}
		else
			return (-1);
	}
	return (count);
}

void	parse_arguments(int tab[N][N], char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			if ((*str - '0') < 1 || (*str - '0') > 4)
			{
				tab[0][0] = -1;
				return ;
			}
			tab[i][j] = *str - '0';
			++j;
			++str;
			if (*str != ' ')
				return ;
			else
				++str;
		}
		++i;
	}
}

void	prepare_solve(const int tab[N][N], int sol[N][N])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			sol[i][j] = 0;
			++j;
		}
		++i;
	}
	if (solve(tab, sol))
		print_solution(sol);
	else
		write(1, "Error\n", 6);
}

int	main(int argc, char *argv[])
{
	char	*str;
	char	*c;
	int		ret[N][N];
	int		sol[N][N];

	if (argc == 2)
	{
		str = argv[1];
		c = argv[0];
		c++;
		if (count_numbers(str) != MAX)
			write(1, "Error\n", 6);
		else
		{
			parse_arguments(ret, str);
			if (ret[0][0] == -1)
				write(1, "Error\n", 6);
			else
				prepare_solve(ret, sol);
		}
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
