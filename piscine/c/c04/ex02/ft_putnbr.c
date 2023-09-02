/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamato-h <mamato-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:15:11 by mamato-h          #+#    #+#             */
/*   Updated: 2023/08/21 21:19:43 by mamato-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	c;

	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if (nb < 0)
	{
		write(1, "-", 1);
		ft_putnbr(nb * (-1));
	}
	else
	{
		if (nb <= 9)
		{
			c = nb + '0';
			write(1, &c, 1);
		}
		else
		{
			ft_putnbr(nb / 10);
			c = (nb % 10) + '0';
			write(1, &c, 1);
		}
	}
}

/*
int main()
{
	ft_putnbr(-2147483648);
	ft_putnbr(2147483647);
	ft_putnbr(0);
	ft_putnbr(123);
	ft_putnbr(-123);
}
*/