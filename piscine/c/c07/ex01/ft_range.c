/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamato-h <mamato-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 13:22:45 by mamato-h          #+#    #+#             */
/*   Updated: 2023/08/31 01:24:42 by mamato-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*array;
	int	*ret;

	if (min >= max)
		return (0);
	array = malloc((max - min) * sizeof(int));
	ret = array;
	while (min < max)
	{
		*array = min;
		++array;
		++min;
	}
	return (ret);
}

/*
#include <stdio.h>
int main()
{
	int *array = ft_range(0, 10);
	for (int i = 0; i < 10; ++i){
		printf("%d ", *array);
		++array;
	}
}
*/