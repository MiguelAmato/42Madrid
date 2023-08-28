#include "ft_stock_str.h"
#include <stdio.h>
#include <stdlib.h>

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

int main()
{
	char *strs[3] = {"Hello", "World", "!"};
	t_stock_str *ret = ft_strs_to_tab(3, strs);
	printf("%s\n", ret[0].str);
	printf("%s\n", ret[1].str);
	printf("%s\n", ret[2].str);
	return (0);
}