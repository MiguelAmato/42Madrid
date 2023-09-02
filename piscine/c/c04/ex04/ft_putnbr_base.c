/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamato-h <mamato-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:15:27 by mamato-h          #+#    #+#             */
/*   Updated: 2023/08/21 21:17:45 by mamato-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_base(int nbr, const char *base, const int n)
{
	if (nbr < n)
		write(1, &base[(unsigned char)nbr % n], 1);
	else
	{
		print_base(nbr / n, base, n);
		write(1, &base[(unsigned char)nbr % n], 1);
	}
}

int	check_repetitions(int *n, char *base)
{
	char	*i;
	char	*j;

	i = base;
	j = base;
	while (*i != '\0')
	{
		j = i + 1;
		while (*j != '\0')
		{
			if (*i == *j || *j == '+' || *j == '-')
				return (1);
			++j;
		}
		++i;
		++(*n);
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		n;
	int		rep;

	n = 0;
	rep = check_repetitions(&n, base);
	if (n > 1 && !rep)
	{
		if (nbr == -2147483648)
			write(1, "-2147483648", 11);
		else
		{
			if (nbr < 0)
			{
				write(1, "-", 1);
				nbr *= -1;
			}
			print_base(nbr, base, n);
		}
	}
}

/*
int main()
{
	ft_putnbr_base();
}
*/