# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamato-h <mamato-h@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/01 15:21:34 by amato             #+#    #+#              #
#    Updated: 2023/10/25 15:40:00 by mamato-h         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = libft/libft.a

SRC = ft_printf.c ft_printf_utils.c ft_printf_parse_args.c

OBJS = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
RC = rcs

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	$(AR) $(RC) $@ $(OBJS)

$(LIBFT):
	make -C libft all

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	make -C libft clean
	rm -f $(OBJS)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re