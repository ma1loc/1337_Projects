CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRC = ft_putchar.c ft_putnbr.c ft_putstr.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all