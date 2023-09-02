/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamato-h <mamato-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:50:07 by mamato-h          #+#    #+#             */
/*   Updated: 2023/08/25 12:00:10 by mamato-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	aux;

	if (nb <= 1)
		return (0);
	aux = 2;
	while (aux <= nb / aux)
	{
		if (nb % aux == 0)
			return (0);
		++aux;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	while (!ft_is_prime(nb))
		++nb;
	return (nb);
}

/*
#include <stdio.h>
int main()
{
	printf("%d -- ", ft_find_next_prime(2147483645));
	
	for (int i = 0; i < 100; ++i)
		printf("%d ", ft_find_next_prime(i));
}
*/