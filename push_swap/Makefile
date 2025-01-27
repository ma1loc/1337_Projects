CC= cc

CFLAGS= -Wall -Wextra -Werror

NAME= push_swap

B_NAME = checker

SRC= main.c push_swap.c push_swap_utils.c swap_operations.c push_operations.c \
	rotate_operations.c r_rotate_operations.c parsing.c  memory_mang.c sort_stacks.c \
	ft_atoi.c ft_strnstr.c ft_strlen.c ft_putstr_fd.c ft_split.c algo.c algo_utils.c \
	algo_second_utils.c sort_stacks_utils.c

OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re

.SECONDARY:  $(OBJ)