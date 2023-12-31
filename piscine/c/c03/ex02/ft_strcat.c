/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamato-h <mamato-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 21:27:47 by mamato-h          #+#    #+#             */
/*   Updated: 2023/08/21 13:03:44 by mamato-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	char	*cpy;

	cpy = dest;
	while (*cpy != '\0')
		++cpy;
	while (*src != '\0')
	{
		*cpy = *src;
		++cpy;
		++src;
	}
	*cpy = '\0';
	return (dest);
}
