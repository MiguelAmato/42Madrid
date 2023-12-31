/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamato-h <mamato-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:22:49 by mamato-h          #+#    #+#             */
/*   Updated: 2023/08/16 13:45:50 by mamato-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	char	*pr;

	pr = str;
	while (*pr != '\0')
	{
		if (*pr >= 'A' && *pr <= 'Z')
			*pr += 32;
		++pr;
	}
	return (str);
}
