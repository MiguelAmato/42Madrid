# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amato <amato@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/05 18:00:55 by amato             #+#    #+#              #
#    Updated: 2023/09/05 18:01:15 by amato            ###   ########.fr        #
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
