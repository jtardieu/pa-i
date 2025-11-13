NAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra

SOURCE =	ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strdup.c \
			ft_strrchr.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_calloc.c \
			ft_strncmp.c \
			ft_atoi.c \
			ft_strnstr.c \
			ft_strchr.c

PART2  =  	ft_substr.c \
			ft_strtrim.c \
			ft_strjoin.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c

BONUS =		ft_lstadd_back_bonus.c \
			ft_lstnew_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstsize_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstmap_bonus.c

OBJ = $(SOURCE:.c=.o) $(PART2:.c=.o)

OBJ_BONUS = $(BONUS:.c=.o)

all: $(NAME)
$(NAME): $(OBJ)
	ar -rc $(NAME) $(OBJ)

bonus: $(OBJ) $(OBJ_BONUS)
	ar -rc $(NAME) $(OBJ) $(OBJ_BONUS)

clean:
	rm -rf $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY : all bonus clean fclean re
