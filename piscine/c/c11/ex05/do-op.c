/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamato-h <mamato-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 03:50:44 by mamato-h          #+#    #+#             */
/*   Updated: 2023/08/31 14:57:39 by mamato-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

const static char	g_ops[] = {'+', '-', '*', '/', '%'};

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


void operate(int op1, char sim, int op2)
{
	int	i;
	int ret;
	int	(*f[5]) (int x, int y);

	f[0] = &add;
	f[1] = &sub;
	f[2] = &mul;
	f[3] = &div;
	f[4] = &mod;

	i = 0;
	while (i < 5)
	{
		if (sim == g_ops[i])
			ret = f[i](op1,op2);
		++i;
	}
	ft_putnbr(ret);
	ft_putstr("\n");
}

int	main(int argc, char *argv[])
{
	int		op1;
	int 	op2;
	char	sim;

	if (argc == 4)
	{
		op1 = ft_atoi(argv[1]);
		sim =  *argv[2];
		op2 = ft_atoi(argv[3]);
		if (sim != '+' && sim != '-' && sim != '/' && sim != '*' && sim != '%')
		{
			ft_putstr("0\n");
			return (0);
		}
		if (op2 == 0 && (sim == '%' || sim == '/'))
		{
			if (sim == '%')
				ft_putstr("Stop : modulo by zero\n");
			else if (sim == '/')
				ft_putstr("Stop : division by zero\n");
			return (0);
		}
		operate(op1, sim, op2);
	}
}
