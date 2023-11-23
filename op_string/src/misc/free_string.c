/*
** EPITECH PROJECT, 2023
** project_name
** File description:
** free_string
*/

#include "op_string.h"

void free_string_op_string(struct op_string_s *o)
{
    free( o->string );
    o->string = NULL;
    o->mem_len = 0;
    o->str_len = 0;
}
