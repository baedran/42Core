# Variables
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT = -L./ -lft
SRC = error.c stack.c node_a_init.c split.c mini.c node_b_init.c \
      rotate.c main.c rev_rotate.c push.c stack_utils.c swap.c turk.c
OBJ = $(SRC:.c=.o)
NAME = my_program

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
