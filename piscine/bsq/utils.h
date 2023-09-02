/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamato-h <mamato-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:50:12 by mamato-h          #+#    #+#             */
/*   Updated: 2023/08/29 16:14:14 by mamato-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

#define FAIL -1
#define SUCCESS 0


typedef struct s_data
{
    int     lines;
    char    empty;
    char    obs;
    char    full;
}   t_data;

int is_printable(char c);

int	ft_atoi(char *str);