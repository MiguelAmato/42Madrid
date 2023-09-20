# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amato <amato@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/05 18:00:55 by amato             #+#    #+#              #
#    Updated: 2023/09/21 00:21:44 by amato            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_isalnum.c ft_isprint.c ft_memcmp.c  ft_putchar_fd.c ft_split.c \
			ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c \
			ft_itoa.c ft_memcpy.c  ft_putendl_fd.c ft_strchr.c  ft_strlcpy.c \
			ft_strnstr.c ft_tolower.c ft_bzero.c ft_isascii.c \
			ft_memmove.c ft_putnbr_fd.c  ft_strdup.c  ft_strlen.c  ft_strrchr.c \
			ft_toupper.c ft_calloc.c  ft_isdigit.c ft_memchr.c  ft_memset.c  \
			ft_putstr_fd.c  ft_strjoin.c ft_strmapi.c ft_strtrim.c	ft_striteri.c
			
OBJS = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $@ $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all