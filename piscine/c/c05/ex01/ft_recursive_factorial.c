/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamato-h <mamato-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:48:35 by mamato-h          #+#    #+#             */
/*   Updated: 2023/08/25 11:59:25 by mamato-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb == 1 || nb == 0)
		return (1);
	else
		return (ft_recursive_factorial(nb - 1) * nb);
}

/*
#include <stdio.h>
int main()
{
	printf("%d", ft_recursive_factorial(0));
}
*/