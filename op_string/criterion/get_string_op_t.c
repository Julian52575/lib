/*
** EPITECH PROJECT, 2023
** project_name
** File description:
** get_string_op_t
*/

#include "op_string.h"

Test(get_string, get_string_op_t) {
    struct op_string_s o = init_op_string();
    char *old = NULL;

    o.set_string(&o, 2, "Hello", " world");
    cr_assert( o.string[0] == 'H' );
    old = o.get_string(&o);
    fprintf(stderr, "! Old is _%s_\n", old);///
    cr_assert( old == o.string, "Got Old _%p_ | O _%p_\n", old, o.string );
    cr_assert( my_strcmp(old, "Hello world") == true );
    o.set_string(&o, 1, "Banana");
    cr_assert( old != o.string, "Got Old _%p_ | O _%p_\n", old, o.string );
    cr_assert( my_strcmp(old, "Hello world") == true );
}
