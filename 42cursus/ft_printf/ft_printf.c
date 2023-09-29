/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamato-h <mamato-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:45:13 by mamato-h          #+#    #+#             */
/*   Updated: 2023/09/29 17:51:41 by mamato-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	parse_arguments(const char *format, va_list ap, const int i)
{
	if (format[i] == 'c')
		ft_putchar_fd(va_arg(ap, int), 1);
	else if (format[i] == 's')
		ft_putstr_fd(va_arg(ap, char *), 1);
	else if (format[i] == 'p')
		print_memory_dir((intptr_t) va_arg(ap, char *));
	else if (format[i] == 'd')
		ft_putnbr_fd(va_arg(ap, long long int), 1);
	else if (format[i] == 'i')
		ft_putnbr_fd(va_arg(ap, long long int), 1);
	else if (format[i] == 'u')
		ft_putnbr_fd(va_arg(ap, long long int), 1);
	//else if (format[i] == 'x')
	//else if (format[i] == 'X')
	else if (format[i] == '%')
		ft_putchar_fd('%', 1);
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
