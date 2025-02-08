CC=cc

CFLAGS=-Wall -Wextra -Werror

NAME=pipex

SRC= pipex.c pipex_utils.c ft_putstr_fd.c ft_strjoin.c ft_strncmp.c \
	ft_split.c ft_strlen.c ft_strnstr.c ft_strdup.c

OBJ=$(SRC:.c=.o)

RM= rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re

.SECONDARY: $(OBJ)
