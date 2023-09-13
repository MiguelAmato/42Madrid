# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amato <amato@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/05 18:00:55 by amato             #+#    #+#              #
#    Updated: 2023/09/12 09:57:06 by amato            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBS = libft.a
SRC_DIR = srcs
SRC = *.c
OBJS = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(LIBS)

$(LIBS): $(OBJS)
	ar rc $@ $(OBJS)
	ranlib $@

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(LIBS)

re: fclean all
