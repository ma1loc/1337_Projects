CC=cc
CFLAGS=-Wall -Wextra -Werror

PRO_NAME=pipex
SRC= pipex.c pipex_utils.c
OBJ=$(SRC:.c=.o)

B_PRO_NAME=pipex_bunus
B_SRC= pipex_bonus.c pipex_bunus_utils.c
B_OBJ=${B_SRC:.c=.o}

RM= rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	ar acs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clear:
	$(RM) $(OBJ)

fclear: clear
	$(RM) $(NAME)

re: fclear all

.PHONY: all clean fclean re
