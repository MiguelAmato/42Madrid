#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

#define FAIL -1
#define SUCCESS 0
#define MAX_INT_SIZE 10

//UTILS---------------------------------------------------------------------------------------------------------
typedef struct s_data
{
    int     lines;
    char    empty;
    char    obs;
    char    full;
}   t_data;

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
//UTILS---------------------------------------------------------------------------------------------------------
//MAIN---------------------------------------------------------------------------------------------------------

int	check_chars(t_data *crs)
{
	if (crs->lines == FAIL)
		return (FAIL);
	if (crs->empty == crs->full || crs->full == crs->obs || crs->obs == crs->empty)
		return (FAIL);
	if (!is_printable(crs->empty) || !is_printable(crs->full) || !is_printable(crs->obs))
		return (FAIL);
	return (SUCCESS);
}

int	read_contents(int fd, t_data *crs)
{
	char	*line;
    int     aux;
	if (fd == FAIL)
		return (FAIL);
    line = malloc((MAX_INT_SIZE + 4) * sizeof(char));
	if (line == 0)
		return (FAIL);
    aux = read(fd, line, 1);
    while (aux == 1 && *line != '\n')
    {
        ++line;
        aux = read(fd, line, 1);
    }
	if (aux == FAIL)
		return (FAIL);
	crs->full = *line;
	--line;
	crs->obs = *line;
	--line;
	crs->empty = *line;
	*line = '\0';
	crs->lines = ft_atoi(&line[0]);
	return (check_chars(crs));
}

int	read_file(char *path)
{
	int		fd;
	char	c;

	fd = open(path, O_RDONLY);
	if (fd == FAIL)
		return (FAIL);
	return (SUCCESS);
}

int main(int argc, char **argv)
{
	int		lines;
	t_data	characters;
	int		aux;
	int		i;

	aux = SUCCESS;
	/*if (argc == 1)
		aux = read_contents(0, "2.ox"");
	else
	{
		i = 1;
		while (i < argc && aux != FAIL)
		{
			aux = read_contents(read_file(argv[i]), &characters);
			++i;
		}
	}*/
	aux = read_contents(read_file("example_file"), &characters);
	if (aux == FAIL)
		return (FAIL);
	printf("%d %c %c %c", characters.lines, characters.full, characters.obs, characters.empty);
	return (0);
}
//MAIN---------------------------------------------------------------------------------------------------------