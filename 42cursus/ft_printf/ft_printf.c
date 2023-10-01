/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amato <amato@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:45:13 by mamato-h          #+#    #+#             */
/*   Updated: 2023/10/01 16:28:31 by amato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
				return (0);
			count += parse_arguments_printf(format, ap, i);
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
	ft_printf(" NULL %s NULL \n", NULL);
	printf(" NULL %s NULL \n", NULL);
	ft_printf(" %p %p \n", 0, 0);
	printf(" %p %p \n", 0, 0);
	ft_printf(" %x \n", 0);
	printf(" %x \n", 0);
	ft_printf(" %x \n", LONG_MAX);
	printf(" %x \n", LONG_MAX);
	ft_printf(" %x \n", LONG_MIN);
	printf(" %x \n", LONG_MIN);
	ft_printf(" %x \n", ULONG_MAX);
	printf(" %x \n", ULONG_MAX);
	ft_printf(" %x \n", 9223372036854775807LL);
	printf(" %x \n", 9223372036854775807LL);
	ft_printf(" %x %x %x %x %x %x %x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf(" %x %x %x %x %x %x %x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	ft_printf(" %X \n", 0);
	printf(" %X \n", 0);
	ft_printf(" %X \n", LONG_MAX);
	printf(" %X \n", LONG_MAX);
	ft_printf(" %X \n", LONG_MIN);
	printf(" %X \n", LONG_MIN);
	ft_printf(" %X \n", ULONG_MAX);
	printf(" %X \n", ULONG_MAX);
	ft_printf(" %X \n", 9223372036854775807LL);
	printf(" %X \n", 9223372036854775807LL);
}