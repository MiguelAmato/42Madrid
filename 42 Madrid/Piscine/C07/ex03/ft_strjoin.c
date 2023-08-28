/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amato <amato@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 02:29:32 by amato             #+#    #+#             */
/*   Updated: 2023/08/28 05:42:35 by amato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int ft_strlen(char *str)
{
	int cont;

	cont = 0;
	while (str[cont])
	{
		cont++;
	}
	return (cont);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int 	i;
	int		j;
	int		cont;
	char	*r;

	i = 0;
	j = 0;
	cont = 0;
	while (i < size)
		j += ft_strlen(strs[i++]);
	r = malloc(j + ((size - 1) * ft_strlen(sep)) + 1 * sizeof(char));
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			r[cont++] = strs[i][j++];
		j = 0;
		while (i < size - 1 && sep[j])
			r[cont++] = sep[j++];
		++i;
	}
	if (size != 0)
		r[cont] = '\0';
	return (r);
}

