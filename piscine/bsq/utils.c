#include "utils.h"

int is_printable(char c)
{
    return (c >= 32 && c <= 126);
}

int	aux(char *str, int *num)
{
	while (*str >= '0' && *str <= '9')
	{
		if (num != 0)
			(*num) *= 10;
		*num = *num + (*str - '0');
		++str;
	}
	if (*str < '0' || *str > '9')
		return (FAIL);
	return (SUCCESS);
}

int	ft_atoi(char *str)
{
	int	ret;
	int	cont;
	int	neg;
	int	num;

	neg = 0;
	ret = 0;
	cont = 0;
	num = 0;
	if ((*str == '+' || *str == '-') && *str != '\0')
	{
		if (*str == '-')
			return (FAIL);
		++str;
	}
	if (cont % 2 != 0)
		neg = 1;
	if (aux(str, &num) == FAIL)
		return (FAIL);
	if (neg)
		return (num * (-1));
	return (num);
}
