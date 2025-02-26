CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = mini_shell/mini_shell.c
OBJ = $(SRC:.c=.o)
NAME = minishell
RM = rm -rf

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
.SECONDRY: $(NAME)
