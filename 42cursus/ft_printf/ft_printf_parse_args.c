/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse_args.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamato-h <mamato-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 20:24:42 by amato             #+#    #+#             */
/*   Updated: 2023/10/25 15:34:46 by mamato-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_arguments_printf(const char *format, va_list ap, const int i)
{
	int	count;

	count = 0;
	if (format[i] == 'c')
		count = ft_putchar_fd(va_arg(ap, int), 1);
	else if (format[i] == 's')
		count = ft_parse_strings(ap);
	else if (format[i] == 'p')
		count = ft_parse_pointers(ap);
	else if (format[i] == 'd')
		count = ft_putnbr_fd(va_arg(ap, int), 1);
	else if (format[i] == 'i')
		count = ft_putnbr_fd(va_arg(ap, int), 1);
	else if (format[i] == 'u')
		count = ft_putnbr_fd(va_arg(ap, unsigned int), 1);
	else if (format[i] == 'x')
		count = ft_parse_hex(ap, 0);
	else if (format[i] == 'X')
		count = ft_parse_hex(ap, 1);
	else if (format[i] == '%')
		count = ft_putchar_fd('%', 1);
	return (count);
}

int	ft_parse_strings(va_list ap)
{
	char	*str;

	str = va_arg(ap, char *);
	if (!str)
		return (ft_putstr_fd("(null)", 1));
	return (ft_putstr_fd(str, 1));
}

int	ft_parse_pointers(va_list ap)
{
	uintptr_t	aux;

	aux = (uintptr_t)va_arg(ap, char *);
	if (!aux)
		return (ft_putstr_fd("0x0", 1));
	return (print_memory_dir(aux));
}

int	ft_parse_hex(va_list ap, int cap)
{
	unsigned int	aux;

	aux = va_arg(ap, unsigned int);
	if (aux == 0)
		return (ft_putnbr_fd(0, 1));
	return (print_rec(aux, cap, "0123456789abcdef"));
}
