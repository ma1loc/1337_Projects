CC=cc
CFLAGS=-Wall -Wextra -Werror
NAME=pipex

SRC= pipex.c pipex_utils.c ft_putstr_fd.c ft_strjoin.c ft_strncmp.c \
	ft_split.c ft_strlen.c ft_strnstr.c
OBJ=$(SRC:.c=.o)

B_SRC= pipex_bonus.c pipex_bunus_utils.c

B_OBJ=${B_SRC:.c=.o}

RM= rm -rf

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

.PHONY: all clean fclean re
