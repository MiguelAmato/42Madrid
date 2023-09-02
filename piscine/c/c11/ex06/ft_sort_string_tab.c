/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamato-h <mamato-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:04:33 by mamato-h          #+#    #+#             */
/*   Updated: 2023/08/31 16:43:40 by mamato-h         ###   ########.fr       */
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

int	ft_strcmp(char *s1, char *s2)
{
	char			*p1;
	char			*p2;
	unsigned int	cont;

	p1 = s1;
	p2 = s2;
	cont = 0;
	while (*p1 != '\0' && *p2 != '\0')
	{
		if (*p1 > *p2)
			return (1);
		else if (*p1 < *p2)
			return (-1);
		++p1;
		++p2;
	}
	if (*p1 != '\0')
		return (1);
	else if (*p2 != '\0')
		return (-1);
	return (0);
}

void	swap(char **fst, char **scd)
{
	char	*aux;

	aux = *fst;
	*fst = *scd;
	*scd = aux;
}

void	ft_sort_string_tab(char **tab)
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
			if (ft_strcmp(tab[j], tab[j + 1]) == 1)
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
	char *aux[] = {"9", "8", "7", "6", "5", "4", "3", "2", "1", "", "."};
	ft_sort_string_tab(aux);
	for (int i = 0; i < 14; i++)
		printf("%s\n", aux[i]);
}
*/