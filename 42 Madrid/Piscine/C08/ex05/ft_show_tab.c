#include "ft_stock_str.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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


char	*ft_strdup(char *src)
{
	int		i;
	char	*ret;

	i = 0;
	ret = malloc((ft_strlen(src) + 1) * sizeof(char));
	if (ret == 0)
		return (0);
	while (src[i])
	{
		ret[i] = src[i];
		++i;
	}
	ret[i] = 0;
	return (ret);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	int			j;
	t_stock_str	*ret;

	i = 0;
	j = 0;
	ret = malloc((ac + 1) * sizeof(t_stock_str));
	while (i < ac)
	{
		ret[i].size = ft_strlen(av[i]);
		ret[i].str = ft_strdup(av[i]);
		ret[i].copy = ft_strdup(av[i]);
		++i;
	}
	ret[i].str = 0;
	return (ret);
}

void   ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void ft_putnbr(int nb)
{
	unsigned int n;
	char c;
	if (nb < 0)
	{
		write(1, "-", 1);
		n = nb * -1;
	}
	else
		n = nb;
	if (n >= 10)
		ft_putnbr(n / 10);
	c = n % 10 + '0';
	write(1,&c,1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != 0)
	{
		ft_putstr(par[i].str);
		ft_putstr("\n");
		ft_putnbr(par[i].size);
		ft_putstr("\n");
		ft_putstr(par[i].copy);
		ft_putstr("\n");
		++i;
	}
}

int main()
{
	char *strs[3] = {"Hello", "World", "!"};
	t_stock_str *ret = ft_strs_to_tab(3, strs);
	ft_show_tab(ret);
	return (0);
}