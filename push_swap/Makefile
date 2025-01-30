CC= cc

CFLAGS= -Wall -Wextra -Werror

NAME= push_swap
B_NAME= checker

SRC= src_push_swap/main.c src_push_swap/push_swap.c src_push_swap/push_swap_utils.c \
     operations/swap_operations.c operations/push_operations.c \
     operations/rotate_operations.c operations/r_rotate_operations.c \
     src_push_swap/parsing.c src_push_swap/memory_mang.c src_push_swap/sort_stacks.c \
     libft/ft_atoi.c libft/ft_strnstr.c libft/ft_strlen.c libft/ft_putstr_fd.c \
     libft/ft_split.c src_push_swap/algo.c src_push_swap/algo_utils.c \
     src_push_swap/algo_second_utils.c src_push_swap/sort_stacks_utils.c

B_SRC= src_push_swap/push_swap.c src_push_swap/push_swap_utils.c src_checker/checker.c src_checker/get_next_line.c src_checker/get_next_line_utils.c \
    operations/swap_operations.c operations/push_operations.c \
    operations/rotate_operations.c operations/r_rotate_operations.c \
    src_push_swap/parsing.c src_push_swap/memory_mang.c src_push_swap/sort_stacks.c \
    libft/ft_atoi.c libft/ft_strnstr.c libft/ft_strlen.c libft/ft_putstr_fd.c \
    libft/ft_split.c src_push_swap/algo.c src_push_swap/algo_utils.c \
    src_push_swap/algo_second_utils.c src_push_swap/sort_stacks_utils.c libft/ft_strncmp.c

OBJ= $(SRC:.c=.o)
B_OBJ= $(B_SRC:.c=.o)

all: $(NAME)

bonus: $(B_NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(B_NAME): $(B_OBJ)
	$(CC) $(CFLAGS) $(B_OBJ) -o $(B_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(B_OBJ)

fclean: clean
	$(RM) $(NAME) $(B_NAME)

re: fclean all

.PHONY: all bonus clean fclean re

.SECONDARY:  $(OBJ) $(B_OBJ)