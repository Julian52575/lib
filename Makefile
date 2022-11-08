##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## it makes files
##

SRC = 	$(wildcard src/*.c lib/my/*.c)

OBJ = $(SRC:.c=.o)

CFLAGS += -Wextra -I./includes -L./lib/my -lmy

NAME = "bsq"

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ)

all:     $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:     fclean all

.PHONY: all clean fclean re