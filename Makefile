##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## it makes files
##

SRC 	= 	lib/my_str_to_word_array.c

CRITERION 	= 	criterion/my_str_to_word_array_t.c

OBJ 	= 	$(SRC:.c=.o)

CFLAGS += -g3 -Wall -Wextra

CRITERIONFLAGS 	= 	-lcriterion

NAME = "unit_test"

all:
	gcc -o $(NAME) \
			$(SRC) \
			$(CRITERION) \
			$(CFLAGS) \
			$(CRITERIONFLAGS)
	echo -e "Running test..."
	./unit_test --crash #--ascii


.PHONY: all
