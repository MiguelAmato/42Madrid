/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamato-h <mamato-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:16:37 by mamato-h          #+#    #+#             */
/*   Updated: 2023/08/31 14:20:43 by mamato-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	add(int op1, int op2)
{
	return (op1 + op2);
}

int	sub(int op1, int op2)
{
	return (op1 - op2);
}

int	mul(int op1, int op2)
{
	return (op1 * op2);
}

int	div(int op1, int op2)
{
	return (op1 / op2);
}

int	mod(int op1, int op2)
{
	return (op1 % op2);
}