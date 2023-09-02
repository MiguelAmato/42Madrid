/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamato-h <mamato-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 21:18:04 by mamato-h          #+#    #+#             */
/*   Updated: 2023/08/20 18:11:59 by bquilumb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#define MAX 16
#define N 4
#define COL_UP 0
#define COL_DOWN 1
#define ROW_LEFT 2
#define ROW_RIGHT 3

int	check_col_up(int elem, const int sol[N][N], int col);
int	check_col_down(int elem, const int sol[N][N], int col);
int	check_row_left(int elem, const int sol[N][N], int row);
int	check_row_right(int elem, const int sol[N][N], int row);

int	is_valid(const int sol[N][N], int row, int col, int elem)
{
	int	i;

	i = 0;
	while (i < N)
	{
		if (elem == sol[row][i] || elem == sol[i][col])
			return (0);
		++i;
	}
	return (1);
}

int	is_solution(const int tab[N][N], const int sol[N][N])
{
	int	i;

	i = 0;
	while (i < N)
	{
		if (!check_col_up(tab[COL_UP][i], sol, i))
			return (0);
		else if (!check_col_down(tab[COL_DOWN][i], sol, i))
			return (0);
		else if (!check_row_left(tab[ROW_LEFT][i], sol, i))
			return (0);
		else if (!check_row_right(tab[ROW_RIGHT][i], sol, i))
			return (0);
		++i;
	}
	return (1);
}

int	find_box(int sol[N][N], int *row, int *col)
{
	int	i;
	int	j;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			if (sol[i][j] == 0)
			{
				*row = i;
				*col = j;
				return (1);
			}
			++j;
		}
		++i;
	}
	return (0);
}

int	solve(const int tab[N][N], int sol[N][N])
{
	int	i;
	int	row;
	int	col;

	if (!find_box(sol, &row, &col) && is_solution(tab, sol))
		return (1);
	i = 1;
	while (i <= N)
	{
		if (is_valid(sol, row, col, i))
		{
			sol[row][col] = i;
			if (solve(tab, sol))
				return (1);
			sol[row][col] = 0;
		}
		++i;
	}
	return (0);
}
