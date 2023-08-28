LIBS = libft.a
SRC = src/*.c
OBJS = $(SRC:.c=.o)
SRC_DIR = srcs
HDR_DIR = includes

CC = cc 
CFLAGS = -Wall -Wextra -Werror

all: $(LIB)

$(LIB):	$(OBJS)
	ar rcs $@ $<

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I $(HDR_DIR) -c $< -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f $(LIBS)

re: fclean all