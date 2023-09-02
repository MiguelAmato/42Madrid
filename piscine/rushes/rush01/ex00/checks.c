/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bquilumb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 17:37:53 by bquilumb          #+#    #+#             */
/*   Updated: 2023/08/20 17:57:43 by bquilumb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define N 4

int	check_col_up(int elem, const int sol[N][N], int col)
{
	int	i;
	int	max;
	int	cont;

	max = sol[0][col];
	cont = 1;
	i = 1;
	while (i < N)
	{
		if (sol[i][col] > max)
		{
			++cont;
			max = sol[i][col];
		}
		++i;
	}
	if (cont != elem)
		return (0);
	return (1);
}

int	check_col_down(int elem, const int sol[N][N], int col)
{
	int	i;
	int	max;
	int	cont;

	max = sol[N - 1][col];
	cont = 1;
	i = N - 2;
	while (i >= 0)
	{
		if (sol[i][col] > max)
		{
			++cont;
			max = sol[i][col];
		}
		--i;
	}
	if (cont != elem)
		return (0);
	return (1);
}

int	check_row_left(int elem, const int sol[N][N], int row)
{
	int	i;
	int	max;
	int	cont;

	max = sol[row][0];
	cont = 1;
	i = 1;
	while (i < N)
	{
		if (sol[row][i] > max)
		{
			++cont;
			max = sol[row][i];
		}
		++i;
	}
	if (cont != elem)
		return (0);
	return (1);
}

int	check_row_right(int elem, const int sol[N][N], int row)
{
	int	i;
	int	max;
	int	cont;

	max = sol[row][N - 1];
	cont = 1;
	i = N - 2;
	while (i >= 0)
	{
		if (sol[row][i] > max)
		{
			++cont;
			max = sol[row][i];
		}
		--i;
	}
	if (cont != elem)
		return (0);
	return (1);
}
