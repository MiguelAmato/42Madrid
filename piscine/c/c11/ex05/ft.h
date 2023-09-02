/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamato-h <mamato-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 04:23:53 by mamato-h          #+#    #+#             */
/*   Updated: 2023/08/31 14:41:13 by mamato-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_H
# define FT_H
#include <unistd.h>

void	operate(int op1, char sim, int op2);

int		ft_strlen(char *str);

void	ft_putstr(char *str);

int		ft_atoi(char *str);

int		add(int op1, int op2);

int		sub(int op1, int op2);

int		mul(int op1, int op2);

int		div(int op1, int op2);

int		mod(int op1, int op2);

#endif