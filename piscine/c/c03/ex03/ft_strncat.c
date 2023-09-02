/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamato-h <mamato-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 21:28:11 by mamato-h          #+#    #+#             */
/*   Updated: 2023/08/17 15:52:56 by mamato-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char			*cpy;
	unsigned int	cont;

	cont = 0;
	cpy = dest;
	while (*cpy != '\0')
		++cpy;
	while (*src != '\0' && cont < nb)
	{
		*cpy = *src;
		++cpy;
		++src;
		++cont;
	}
	*cpy = '\0';
	return (dest);
}
