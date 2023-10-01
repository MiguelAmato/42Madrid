/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse_args.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amato <amato@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 20:24:42 by amato             #+#    #+#             */
/*   Updated: 2023/10/01 21:00:27 by amato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_strings(va_list ap)
{
	char	*str;

	str = va_arg(ap, char *);
	if (!str)
		str = "(null)";
	return (ft_putstr_fd(str, 1));
}
int	ft_parse_pointers(va_list ap)
{
	uintptr_t	aux;

	aux = (uintptr_t) va_arg(ap, char *);
	if (!aux)
		return (ft_putstr_fd("(null)", 1));
	return (print_memory_dir(aux));
}