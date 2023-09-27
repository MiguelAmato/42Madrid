/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamato-h <mamato-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:45:13 by mamato-h          #+#    #+#             */
/*   Updated: 2023/09/27 16:25:28 by mamato-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdarg.h>

void	parse_argumments(char *format, va_list ap, const int i)
{
	
}

int	ft_printf(char const *format, ...)
{
	int		i;
	va_list	ap;

	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			++i;
			if (!format[i])
				return (0); // No se que tiene que hacer esto la verdad
			parse_arguments(format, ap, i);
		}
		else
			ft_putchar_fd(format[i], 1);
		++i;
	}
	va_end(ap);
}
