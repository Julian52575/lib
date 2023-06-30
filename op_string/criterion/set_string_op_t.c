/*
** EPITECH PROJECT, 2023
** project_name
** File description:
** set_string_op_t
*/

#include "op_string.h"

static bool my_strcmp(char *s1, char *s2)
{
    for (int i = 0; s1 && s2 && s1[i] && s2[i]; i++) {
        if ( s1[i] != s2[i] )
            return false;
    }
    if (!s1 && s2)
        return false;
    else if (s1 && !s2)
        return false;
    return true;
}

Test(set_1_string, set_string_t) {
    op_string_t o = init_op_string();

    o.set_string(&o, 1, "hello");
    cr_assert(o.string != NULL);
    cr_assert(o.string[0] == 'h');
    cr_assert(o.mem_len == 5);
    cr_assert(o.str_len == 5);
}

Test(set_4_string, set_string_t)
{
    op_string_t o = init_op_string();

    o.set_string(&o, 4, "Hello", "world", "test", "banana");
    cr_assert( o.mem_len == 20 );
    cr_assert( o.str_len == 20 );
    cr_assert( my_strcmp( o.string, "Helloworldtestbanana" ) == true );
}
