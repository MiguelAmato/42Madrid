/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamato-h <mamato-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:49:33 by mamato-h          #+#    #+#             */
/*   Updated: 2023/08/25 12:00:04 by mamato-h         ###   ########.fr       */
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

/*
#include <stdio.h>
int main(){
	printf("%d-- ", ft_is_prime(2147483647));

	for(int i = 0; i < 7950; ++i)
	{
		if (ft_is_prime(i))
			printf("%d ", i);
	}
	
}
*/