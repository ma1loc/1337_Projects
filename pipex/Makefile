CC=cc
CFLAGS=-Wall -Wextra -Werror
NAME=pipex
SRC=
OBJ=$(SRC:.c=.o)
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
