/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamato-h <mamato-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:37:47 by mamato-h          #+#    #+#             */
/*   Updated: 2023/08/12 18:09:02 by mamato-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	*copia;
	int	aux;
	int	cont;

	copia = tab;
	copia += size - 1;
	cont = 0;
	while (cont < size / 2)
	{
		aux = *tab;
		*tab = *copia;
		*copia = aux;
		++tab;
		--copia;
		++cont;
	}
	tab -= (size / 2);
}
