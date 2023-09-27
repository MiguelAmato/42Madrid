# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamato-h <mamato-h@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/05 18:00:55 by amato             #+#    #+#              #
#    Updated: 2023/09/27 15:44:07 by mamato-h         ###   ########.fr        #
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

SRC_BONUS = ft_lstnew_bonus.c ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c \
			ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c \
			ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstsize_bonus.c

OBJS_BONUS = $(SRC_BONUS:.c=.o)

BONUS_RELINK = .bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
RC = rc

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(RC) $@ $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

bonus: $(BONUS_RELINK)

$(BONUS_RELINK): $(NAME) $(OBJS) $(OBJS_BONUS)
	$(AR) $(RC) $(NAME) $(OBJS) $(OBJS_BONUS)
	touch $(BONUS_RELINK)

clean:
	rm -f $(OBJS) $(OBJS_BONUS) $(BONUS_RELINK)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re