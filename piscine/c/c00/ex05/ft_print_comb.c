/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamato-h <mamato-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:37:39 by mamato-h          #+#    #+#             */
/*   Updated: 2023/08/16 11:47:16 by mamato-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	init_chars(char *fst, char scd[], char thd[])
{
	*fst = '0';
	scd[0] = '1';
	scd[1] = '1';
	thd[0] = '3';
	thd[1] = '2';
	thd[2] = '2';
}

void	update_chars(char *fst, char scd[], char thd[])
{
	++(*fst);
	++scd[1];
	scd[0] = scd[1];
	++thd[2];
	thd[0] = thd[2];
	thd[1] = thd[2];
}

void	write_chars(char fst, char scd, char thd)
{
	write(1, ", ", 2);
	write(1, &fst, 1);
	write(1, &scd, 1);
	write(1, &thd, 1);
}

void	ft_print_comb(void)
{
	char	fst;
	char	scd[2];
	char	thd[3];

	write(1, "012", 3);
	init_chars(&fst, scd, thd);
	while (fst <= '7')
	{
		while (scd[0] <= '8')
		{
			while (thd[0] <= '9')
			{
				write_chars(fst, scd[0], thd[0]);
				++thd[0];
			}
			++thd[1];
			thd[0] = thd[1];
			++scd[0];
		}
		update_chars(&fst, scd, thd);
	}
}
