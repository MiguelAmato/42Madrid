/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamato-h <mamato-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 02:55:09 by mamato-h          #+#    #+#             */
/*   Updated: 2023/08/31 16:39:45 by mamato-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*ret;

	i = 0;
	ret = malloc(length * sizeof(int));
	while (i < length)
	{
		ret[i] = (*f)(tab[i]);
		++i;
	}
	return (ret);
}
