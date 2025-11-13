NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra

LIBFT = libft/libft.a

SOURCE = printf.c

OBJ = $(SOURCE:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	cp -rf $(LIBFT) $(NAME)
	ar -rcs $@ $(OBJ)

$(LIBFT):
	make -C libft

clean:
	rm -rf $(OBJ)
	make -C libft clean

fclean: clean
	rm -rf $(NAME)
	make -C libft fclean

re: fclean all

.PHONY : all clean fclean re
