/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamato-h <mamato-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:45:13 by mamato-h          #+#    #+#             */
/*   Updated: 2023/09/29 18:52:10 by mamato-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libftprintf.h"
#include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

# define MAX 16

const static char	g_hex[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
		'a', 'b', 'c', 'd', 'e', 'f'};

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		++i;
	}
	return (i);
}

int	ft_putnbr_fd(long long int n, int fd)
{
	char	c;
	int		count;

	count = 0;
	if (n == LLONG_MIN)
		return (ft_putstr_fd("-9223372036854775808", fd));
	else
	{
		if (n < 0)
		{
			count += write(fd, "-", 1);
			n = -n;
			count += ft_putnbr_fd(n, fd);
		}
		else if (n <= 9)
			count += ft_putchar_fd((char)(n + '0'), fd);
		else
		{
			c = (n % 10) + '0';
			count += ft_putnbr_fd(n / 10, fd);
			count += ft_putchar_fd(c, fd);
		}
	}
	return (count);
}

int	print_memory_dir(intptr_t addr)
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
	return (0);
}

static int	parse_arguments(const char *format, va_list ap, const int i)
{
	int	count;

	count = 0;
	if (format[i] == 'c')
		count += ft_putchar_fd(va_arg(ap, int), 1);
	else if (format[i] == 's')
		count += ft_putstr_fd(va_arg(ap, char *), 1);
	else if (format[i] == 'p')
		count += print_memory_dir((intptr_t) va_arg(ap, char *));
	else if (format[i] == 'd')
		count += ft_putnbr_fd(va_arg(ap, int), 1);
	else if (format[i] == 'i')
		count += ft_putnbr_fd(va_arg(ap, int), 1);
	else if (format[i] == 'u')
		count += ft_putnbr_fd(va_arg(ap, unsigned int), 1);
	//else if (format[i] == 'x')
	//else if (format[i] == 'X')
	else if (format[i] == '%')
		count += ft_putchar_fd('%', 1);
	return (count);
}

int	ft_printf(char const *format, ...)
{
	int		i;
	int		count;
	va_list	ap;

	i = 0;
	count = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			++i;
			if (!format[i])
				return (0); // No se que tiene que hacer esto la verdad
			count += parse_arguments(format, ap, i);
		}
		else
			count += ft_putchar_fd(format[i], 1);
		++i;
	}
	va_end(ap);
	return (count);
}

#include <stdio.h>

int	main(void)
{
	char c = 'c';
	char *s = "Esto es un string";
	int i = INT_MIN;
	unsigned int u = UINT_MAX;
	printf("Lo que imprime ft_printf:\n");
	int n = ft_printf("Hola que tal, c: %c, s: %s, p: %p, d: %d, i: %i, u: %u, %%", c, s, s, i, i, u);
	printf("\nLo que devuelve ft_printf: %d\n", n);
	printf("Lo que imprime printf:\n");
	n = printf("Hola que tal, c: %c, s: %s, p: %p, d: %d, i: %i, u: %u, %%", c, s, s, i, i, u);
	printf("\nLo que devuelve printf: %d\n", n);
}
