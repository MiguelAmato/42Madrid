/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amato <amato@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 19:44:44 by mamato-h          #+#    #+#             */
/*   Updated: 2023/10/01 20:51:12 by amato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_arguments_printf(const char *format, va_list ap, const int i)
{
	int	count;

	count = 0;
	if (format[i] == 'c')
		count += ft_putchar_fd(va_arg(ap, int), 1);
	else if (format[i] == 's')
		count += ft_parse_strings(ap);
	else if (format[i] == 'p')
		count += ft_parse_pointers(ap);
	else if (format[i] == 'd')
		count += ft_putnbr_fd(va_arg(ap, int), 1);
	else if (format[i] == 'i')
		count += ft_putnbr_fd(va_arg(ap, int), 1);
	else if (format[i] == 'u')
		count += ft_putnbr_fd(va_arg(ap, unsigned int), 1);
	else if (format[i] == 'x')
		count += print_rec(va_arg(ap, unsigned long long int), 0);
	else if (format[i] == 'X')
		count += print_rec(va_arg(ap, unsigned long long int), 1);
	else if (format[i] == '%')
		count += ft_putchar_fd('%', 1);
	return (count);
}

int	print_rec(unsigned long long n, const int cap)
{
	int	count;

	count = 0;
	if (n == 0)
		return (0);
	count += print_rec(n / MAX, cap);
	if (cap && n % MAX > 9)
		count += ft_putchar_fd((char)g_hex[n % MAX] - 32, 1);
	else
		count += ft_putchar_fd((char)g_hex[n % MAX], 1);
	return (count);
}

int	print_memory_dir(uintptr_t n)
{
	ft_putstr_fd("0x", 1);
	return (print_rec(n, 0) + 2);
}
