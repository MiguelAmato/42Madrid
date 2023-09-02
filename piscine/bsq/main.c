/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamato-h <mamato-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:47:00 by mamato-h          #+#    #+#             */
/*   Updated: 2023/08/29 16:14:20 by mamato-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	read_contents(int fd, t_data *crs)
{
	char	*c;

	if (fd == FAIL)
		return (FAIL);
	if (read(fd, c, 1) == FAIL || read(fd, &crs->empty, 1) == FAIL || read(fd, &crs->obs, 1) == FAIL
		|| read(fd, &crs->full, 1) == FAIL)
		return (FAIL);
	printf("HOLA");
	crs->lines = atoi(c);
	if (*c != '0' && crs->lines == 0)
		return (FAIL);
	if (!is_printable(crs->empty) || !is_printable(crs->full) ||
		!is_printable(crs->obs))
		return (FAIL);
	if (crs->empty == crs->full || crs->empty == crs->obs
		|| crs->full == crs->obs)
		return (FAIL);
	
	return (SUCCESS);
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
	if (argc == 1)
		aux = read_contents(0, &characters);
	else
	{
		i = 1;
		while (i < argc && aux != FAIL)
		{
			aux = read_contents(read_file(argv[i]), &characters);
			++i;
		}
	}
	if (aux == FAIL)
		return (FAIL);
	return (0);
}
