/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amato <amato@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:36:32 by amato             #+#    #+#             */
/*   Updated: 2023/10/01 15:38:43 by amato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	ft_putnbr_fd(long long int n, int fd)
{
	char	c;
	int		count;

	count = 0;
	if (n == LLONG_MIN)
		return (ft_putstr_fd("-9223372036854775808", fd));
	else
	{
		if (n < 0)
		{
			count += write(fd, "-", 1);
			n = -n;
			count += ft_putnbr_fd(n, fd);
		}
		else if (n <= 9)
			count += ft_putchar_fd((char)(n + '0'), fd);
		else
		{
			c = (n % 10) + '0';
			count += ft_putnbr_fd(n / 10, fd);
			count += ft_putchar_fd(c, fd);
		}
	}
	return (count);
}
