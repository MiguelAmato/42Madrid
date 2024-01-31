/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amato <amato@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:28:09 by amato             #+#    #+#             */
/*   Updated: 2024/01/31 12:15:02 by amato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define NL '\n'
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);

#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100
#endif
