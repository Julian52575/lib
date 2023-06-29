/*
** EPITECH PROJECT, 2023
** project_name
** File description:
** init_op_t
*/

#include "op_string.h"

static int my_strcmp(char *str1, char *str2)
{
    int i = 0;

    if (!str1 && !str2)
        return 0;

    if ( (!str1 && str2) || (str1 && !str2) )
        return 1;

    for (; str1[i] && str2[i]; i++) {
        if (str1[i] != str2[i])
            return 1;
    }
    return 0;
}

Test(init_empty_str, init_testing) {
    op_string_t o = init_op_string(NULL);

    cr_assert( o.string == NULL );
    cr_assert( o.str_len == 0 );
    cr_assert( o.mem_len == 0 );
}

Test(init_str, init_testing) {
    cr_log_warn("STARTING INIT WITH STR\n");
    char test[] = "Hello world";
    op_string_t o = init_op_string( &test[0] );

    cr_log_warn("{C} String is _%s_ for init with str test.\n", o.string);
    cr_assert( o.string != NULL );
    cr_assert( my_strcmp(o.string, test ) == 0,
            "Got string _%s_ insd _%s_\n", o.string, test );
    cr_assert( o.str_len == 11 );
    cr_assert( o.mem_len == 12 );
}
