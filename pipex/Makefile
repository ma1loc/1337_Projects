CC=cc

CFLAGS=-Wall -Wextra -Werror

PRO_NAME=pipex

SRC= pipex.c pipex_utils.c ft_putstr_fd.c ft_strjoin.c ft_strncmp.c \
	ft_split.c ft_strlen.c ft_strnstr.c

OBJ=$(SRC:.c=.o)

B_PRO_NAME=pipex_bunus

B_SRC= pipex_bonus.c pipex_bunus_utils.c

B_OBJ=${B_SRC:.c=.o}

RM= rm -rf

all: $(PRO_NAME)

$(PRO_NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(PRO_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clear:
	$(RM) $(OBJ)

fclear: clear
	$(RM) $(NAME)

re: fclear all

.PHONY: all clean fclean re
