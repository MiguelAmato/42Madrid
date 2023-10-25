/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamato-h <mamato-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:45:13 by mamato-h          #+#    #+#             */
/*   Updated: 2023/10/07 19:36:37 by mamato-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *format, ...)
{
	int		i;
	int		count;
	int		parse;
	va_list	ap;

	i = -1;
	count = 0;
	parse = 0;
	va_start(ap, format);
	while (format[++i])
	{
		if (format[i] == '%')
		{
			parse = parse_arguments_printf(format, ap, ++i);
			if (parse == -1)
				return (-1);
			count += parse;
		}
		else
			count += ft_putchar_fd(format[i], 1);
	}
	va_end(ap);
	return (count);
}
