CC= cc

CFLAGS= -Wall -Wextra -Werror

NAME= push_swap

SRC= push_swap.c ft_strlen.c ft_putstr_fd.c ft_split.c ft_atoi.c parsing.c

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
