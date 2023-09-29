/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamato-h <mamato-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 19:40:54 by mamato-h          #+#    #+#             */
/*   Updated: 2023/09/27 19:47:57 by mamato-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINT_H
# define LIBFTPRINT_H
# include "libft/libft.h"
# include <stdarg.h>
# include <stdint.h>

# define MAX 16

const static char	g_hex[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
		'a', 'b', 'c', 'd', 'e', 'f'};

int					ft_printf(char const *format, ...);

void				print_memory_dir(intptr_t addr);

#endif