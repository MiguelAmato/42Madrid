/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamato-h <mamato-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 21:30:26 by mamato-h          #+#    #+#             */
/*   Updated: 2023/08/23 12:20:07 by mamato-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

void	ft_sort_int_tab(char **tab, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
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

int	main(int argc, char *argv[])
{
	int	i;

	if (argc > 1)
	{
		++argv;
		ft_sort_int_tab(argv, argc - 1);
		i = 0;
		while (i < argc - 1)
		{
			while (*argv[i] != '\0')
			{
				write(1, argv[i], 1);
				++argv[i];
			}
			write(1, "\n", 1);
			++i;
		}
	}
	return (0);
}
