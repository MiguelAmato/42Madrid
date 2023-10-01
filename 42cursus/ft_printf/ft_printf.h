/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amato <amato@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 19:40:54 by mamato-h          #+#    #+#             */
/*   Updated: 2023/10/01 20:44:57 by amato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <limits.h>
# include <stdarg.h>
# include <stdint.h>

# define MAX 16

static const char	g_hex[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
	'a', 'b', 'c', 'd', 'e', 'f'};

int	ft_printf(char const *format, ...);

int	parse_arguments_printf(const char *format, va_list ap, const int i);

int	print_rec(unsigned long long int n, const int cap);

int	print_memory_dir(uintptr_t n);

int	ft_parse_strings(va_list ap);

int	ft_parse_pointers(va_list ap);

#endif