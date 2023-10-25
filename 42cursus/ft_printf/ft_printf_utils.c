/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamato-h <mamato-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 19:44:44 by mamato-h          #+#    #+#             */
/*   Updated: 2023/10/25 15:40:44 by mamato-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_rec(unsigned long long n, const int cap, char g_hex[])
{
	int	count;

	count = 0;
	if (n == 0)
		return (0);
	count += print_rec(n / MAX, cap, g_hex);
	if (cap && n % MAX > 9)
		count += ft_putchar_fd((char)g_hex[n % MAX] - 32, 1);
	else
		count += ft_putchar_fd((char)g_hex[n % MAX], 1);
	return (count);
}

int	print_memory_dir(uintptr_t n)
{
	ft_putstr_fd("0x", 1);
	return (print_rec(n, 0, "0123456789abcdef") + 2);
}
