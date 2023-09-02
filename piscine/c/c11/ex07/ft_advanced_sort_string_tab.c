/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamato-h <mamato-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:36:39 by mamato-h          #+#    #+#             */
/*   Updated: 2023/08/31 16:43:30 by mamato-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char **str)
{
	int	cont;

	cont = 0;
	while (str[cont] != 0)
		++cont;
	return (cont);
}

void	swap(char **fst, char **scd)
{
	char	*aux;

	aux = *fst;
	*fst = *scd;
	*scd = aux;
}

void ft_advanced_sort_string_tab(char **tab, int(*cmp)(char *, char *))
{
	int	i;
	int	j;
	int	size;

	i = 0;
	j = 0;
	size = ft_strlen(tab);
	while (i < size - 1)
	{
		while (j < size - i - 1)
		{
			if ((*cmp)(tab[j], tab[j + 1]) > 0)
				swap(&tab[j], &tab[j + 1]);
			++j;
		}
		++i;
		j = 0;
	}
}

/*
#include <stdio.h>
int main()
{
	char *aux[] = {"9", "8", "7", "6", "5", "4", "3", "2", "1", "", ".", 0};
	ft_advanced_sort_string_tab(aux, &ft_strcmp);
	for (int i = 0; i < 11; i++)
		printf("%s\n", aux[i]);
}
*/