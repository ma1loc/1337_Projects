CC= cc

CFLAGS= -Wall -Wextra -Werror

NAME= push_swap

SRC= main.c push_swap.c push_swap_utils.c swap_operations.c push_operations.c \
     rotate_operations.c r_rotate_operations.c parsing.c \
     ft_strnstr.c ft_strlen.c ft_putstr_fd.c ft_split.c ft_atoi.c parsing.c \

OBJ=$(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.SCENDARY: $(OBJ)

.PHONY: clean fclean re
