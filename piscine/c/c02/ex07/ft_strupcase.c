/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamato-h <mamato-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:00:39 by mamato-h          #+#    #+#             */
/*   Updated: 2023/08/16 13:30:00 by mamato-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	char	*pr;

	pr = str;
	while (*pr != '\0')
	{
		if (*pr >= 'a' && *pr <= 'z')
			*pr -= 32;
		++pr;
	}
	return (str);
}
