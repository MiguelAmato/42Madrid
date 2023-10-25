/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamato-h <mamato-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 19:40:54 by mamato-h          #+#    #+#             */
/*   Updated: 2023/10/25 15:37:16 by mamato-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <limits.h>
# include <stdarg.h>
# include <stdint.h>

# define MAX 16

int	ft_printf(char const *format, ...);

int	parse_arguments_printf(const char *format, va_list ap, const int i);

int	print_rec(unsigned long long n, const int cap, char g_hex[]);

int	print_memory_dir(uintptr_t n);

int	ft_parse_strings(va_list ap);

int	ft_parse_pointers(va_list ap);

int	ft_parse_hex(va_list ap, int cap);

#endif