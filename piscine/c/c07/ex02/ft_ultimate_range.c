/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamato-h <mamato-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 13:22:54 by mamato-h          #+#    #+#             */
/*   Updated: 2023/08/31 01:19:35 by mamato-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	if (min >= max)
		return (0);
	*range = malloc((max - min) * sizeof(int));
	if (*range == 0)
		return (-1);
	i = min;
	while (i < max)
	{
		**range = i;
		++(*range);
		++i;
	}
	*range -= (max - min);
	return (max - min);
}

/*
#include <stdio.h>
int main()
{
    int *array; 
	int  range = ft_ultimate_range(&array, -12, 12);
    printf("%d: ", range);
	for (int i = 0; i < 24; ++i){
		printf("%d ", *array);
		++array;
	}
}
*/