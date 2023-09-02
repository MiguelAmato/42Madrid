# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamato-h <mamato-h@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/28 22:58:15 by mamato-h          #+#    #+#              #
#    Updated: 2023/08/31 18:00:53 by mamato-h         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBS = libft.a
SRC_DIR = srcs
SRC = srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strcmp.c srcs/ft_strlen.c \
		srcs/ft_swap.c
OBJS = $(SRC:.c=.o)
HDR_DIR = includes

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(LIBS)

$(LIBS): $(OBJS)
	ar rc $@ $(OBJS)
	ranlib $@

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(HDR_DIR)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(LIBS)

re: fclean all
