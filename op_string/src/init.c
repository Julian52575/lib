/*
** EPITECH PROJECT, 2023
** project_name
** File description:
** init
*/

#include "op_string.h"
void set_string_op_string(struct op_string_s *, int, ...);
void set_lenght_op_string(struct op_string_s *, int l);

char *get_string_op_string(struct op_string_s *o);
int get_lenght_op_string(struct op_string_s *o);
char *get_indexes_op_string(struct op_string_s *o, int start, int end);
int get_word_count_op_string(struct op_string_s *, char word[]);
char *get_string_copy_op_string(struct op_string_s *);

bool compare_string_op_string(struct op_string_s *, char other[]);
char **to_word_array_op_string(struct op_string_s *, char);
char **tok(struct op_string_s *, char);
void free_string(struct op_string_s *);


static void set_function_pointer(struct op_string_s *o)
{
    o->set_string = &set_string_op_string;
    //o->set_lenght = &set_lenght_op_string;
}

static void get_function_pointer(struct op_string_s *o)
{

    o->get_string = &get_string_op_string;/*
    o->get_lenght = &get_lenght_op_string;
    o->get_indexes = &get_indexes_op_string;
    o->get_word_count = &get_word_count_op_string;
    o->get_string_copy = &get_string_copy_op_string;
    */
}

static void misc_function_pointer(struct op_string_s *o)
{
    /*
    o->to_word_array = &to_word_array_op_string;
    o->free_string = &free_op_string;
    */
}

static void set_string(struct op_string_s *o)
{
    o->string = NULL;
    o->str_len = 0;
    o->mem_len = 0;
}

struct op_string_s init_op_string(void)
{
    struct op_string_s o = {0};

    set_function_pointer(&o);
    get_function_pointer(&o);
    misc_function_pointer(&o);
    set_string(&o);
    return o;
}
