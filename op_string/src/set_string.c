/*
** EPITECH PROJECT, 2023
** project_name
** File description:
** set_string
*/

#include "op_string.h"

static void set_to_null(struct op_string_s o)
{
    if (o.string)
        free(o.string);
    o.str_len = 0;
    o.mem_len = 0;
    o.string = NULL;
}

static void allocate_memory(struct op_string_s o, int size)
{
    //if ( o.string )
    //    free(o.string);
    o.string = malloc(sizeof(char) * (size + 1));
    o.mem_len = size;
}

static void copy_string(struct op_string_s o, char *str, int str_lenght)
{
    int i = 0;

    for (; str[ i ]; i++)
        o.string[ i ] = str[ i ];
    o.string[ i ] = '\0';
}

void set_string_op_string(struct op_string_s o, char *str)
{
    int str_lenght = my_strlen_op(str);

    fprintf(stderr, "Starting SET STRING with _%s_ | Str len _%d_ | Malloc len _%d_\n",
            str, str_lenght, o.mem_len);///

    if (!str)
        return set_to_null(o);
    if (str_lenght > o.mem_len) {
        fprintf(stderr, "1\n");
        allocate_memory(o, str_lenght);
    }
    fprintf(stderr, "2\n");
    copy_string(o, str, str_lenght);
    fprintf(stderr, "Exiting with _%s_\n", o.string);//
}
