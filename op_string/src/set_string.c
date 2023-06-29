/*
** EPITECH PROJECT, 2023
** project_name
** File description:
** set_string
*/

#include "op_string.h"

static void set_to_null(struct op_string_s *o)
{
    if (o->string)
        free(o->string);
    o->str_len = 0;
    o->mem_len = 0;
    o->string = NULL;
}

static void allocate_memory(struct op_string_s *o, int size)
{
    if ( o->string )
        free(o->string);
    o->string = malloc(sizeof(char) * (size + 1));
    o->mem_len = size;
}

static void copy_string(struct op_string_s *o, char *str, int str_lenght)
{
    int i = 0;

    for (; i < str_lenght; i++)
        o->string[ i ] = str[ i ];
    o->str_len = i;
    o->string[ i ] = '\0';
    for (; i < o->mem_len; i++)
        o->string[ i ] = '\0';
}

void set_string_op_string(struct op_string_s *o, char *str)
{
    int str_lenght = my_strlen_op(str);

    if (!str)
        return set_to_null(o);
    if (str_lenght > o->mem_len)
        allocate_memory(o, str_lenght);
    copy_string(o, str, str_lenght);
}

