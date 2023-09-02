/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamato-h <mamato-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:48:26 by mamato-h          #+#    #+#             */
/*   Updated: 2023/08/25 11:59:18 by mamato-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	ret;

	if (nb < 0)
		return (0);
	else if (nb == 0)
		return (1);
	ret = 1;
	while (nb > 0)
	{
		ret *= nb;
		--nb;
	}
	return (ret);
}

/*
#include <stdio.h>
int main()
{
	printf("%d", ft_iterative_factorial(10));
}
*/