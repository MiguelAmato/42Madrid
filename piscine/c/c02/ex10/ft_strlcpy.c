/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamato-h <mamato-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 20:55:17 by mamato-h          #+#    #+#             */
/*   Updated: 2023/08/16 13:41:46 by mamato-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	cont;
	char			*src_c;
	char			*dest_c;

	src_c = src;
	dest_c = dest;
	cont = 0;
	if (size > 0)
	{
		while (*src_c != '\0' && cont < size - 1)
		{
			*dest_c = *src_c;
			++dest_c;
			++src_c;
			++cont;
		}
	}
	*dest_c = '\0';
	while (*src_c != '\0')
	{
		++cont;
		++src_c;
	}
	return (cont);
}
