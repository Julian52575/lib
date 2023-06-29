/*
** EPITECH PROJECT, 2023
** OP_string
** File description:
** an useful homebrewed string lib
*/

#include <criterion/criterion.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <alloca.h>
#include <stdbool.h>

int my_strlen_op(char *str);

typedef struct op_string_s {
    char * string;
    int str_len;
    int mem_len;

    //Set functions
    void (*set_string) ( struct op_string_s,char[]);
    void (*set_lenght) (struct op_string_s, int); //adds an \0 starting from the set lenght;

    //Get functions
    char * (*get_string) (struct op_string_s);
    int (*get_lenght) (struct op_string_s);
    char * (*get_indexes) (struct op_string_s, int, int);
    int (*get_word_count) (struct op_string_s, char word[]);
    char * (*get_string_copy) (struct op_string_s);

    //Others
    char ** (*to_word_array) (struct op_string_s, char);
    bool (*compare) (struct op_string_s, char *);
    void (*free_string) (struct op_string_s);

} op_string_t;

op_string_t init_op_string( char *string );
