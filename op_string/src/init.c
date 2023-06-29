/*
** EPITECH PROJECT, 2023
** project_name
** File description:
** init
*/

#include "op_string.h"
void set_string_op_string(struct op_string_s *, char str[]);
void set_lenght_op_string(struct op_string_s *, int l);

char *get_string_op_string(struct op_string_s *o);
int get_lenght_op_string(struct op_string_s *o);
char *get_indexes_op_string(struct op_string_s *o, int start, int end);
int get_word_count_op_string(struct op_string_s, char word[]);
char *get_string_copy_op_string(struct op_string_s);

bool compare_string_op_string(struct op_string_s, char *);
char **to_word_array_op_string(struct op_string_s, char);
void free_string(struct op_string_s);

static void init_string(struct op_string_s *o, char *str)
{
    o->string = NULL;
    o->str_len = 0;
    o->mem_len = 0;
    if (str && str[0])
        o->set_string(o, str);
}

struct op_string_s init_op_string(char *str)
{
    struct op_string_s o = {0};

    o.set_string = &set_string_op_string;
    /*
    o.set_lenght = &set_lenght_op_string;

    o.get_string = &get_string_op_string;
    o.get_lenght = &get_lenght_op_string;
    o.get_indexes = &get_indexes_op_string;
    o.get_word_count = &get_word_count_op_string;
    o.get_string_copy = &get_string_copy_op_string;

    o.to_word_array = &to_word_array_op_string;
    o.free_string = &free_op_string;*/
    init_string(&o, str);
    return o;
}
