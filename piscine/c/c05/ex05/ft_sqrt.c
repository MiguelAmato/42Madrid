/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamato-h <mamato-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:49:24 by mamato-h          #+#    #+#             */
/*   Updated: 2023/08/25 11:59:56 by mamato-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	ini;
	int	end;
	int	mid;

	if (nb <= 0)
		return (0);
	else if (nb == 1)
		return (nb);
	ini = 1;
	end = nb / 2;
	while (ini <= end)
	{
		mid = (ini + end) / 2;
		if (nb / mid == mid && nb % mid == 0)
			return (mid);
		else if (mid < nb / mid)
			ini = mid + 1;
		else
			end = mid - 1;
	}
	return (0);
}

/*
#include <stdio.h>
int main(){
    printf("%d\n", ft_sqrt(-1));
    printf("%d\n", ft_sqrt(0));
    printf("%d\n", ft_sqrt(1));
    printf("%d\n", ft_sqrt(16));
    printf("%d\n", ft_sqrt(152399025));
}
*/