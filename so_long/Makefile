CC= cc

CFLAGS= -Wall -Wextra -Werror

RM= rm -rf

NAME= so_long

SRC= 

OBJ= $(SRC:.c=.o)

all: $(NAME)

$(NAME) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all