/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamato-h <mamato-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 17:11:41 by mamato-h          #+#    #+#             */
/*   Updated: 2023/08/16 13:27:56 by mamato-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	cont;
	char			*src_c;
	char			*dest_c;

	src_c = src;
	dest_c = dest;
	cont = 0;
	while (*src_c != '\0' && cont < n)
	{
		*dest_c = *src_c;
		++dest_c;
		++src_c;
		++cont;
	}
	while (cont < n)
	{
		*dest_c = '\0';
		++dest_c;
		++cont;
	}
	return (dest);
}
