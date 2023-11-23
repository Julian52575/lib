/*
** EPITECH PROJECT, 2023
** project_name
** File description:
** set_string_op_t
*/

#include "op_string.h"

Test(set_1_string, set_string_t) {
    op_string_t o = init_op_string();

    o.set_string(&o, 1, "hello");
    cr_assert(o.string != NULL);
    cr_assert(o.string[0] == 'h');
    cr_assert(o.mem_len == 5);
    cr_assert(o.str_len == 5);
}

Test(set_4_string, set_string_t) {
    op_string_t o = init_op_string();

    o.set_string(&o, 4, "Hello", "world", "test", "banana");
    cr_assert( o.mem_len == 20 );
    cr_assert( o.str_len == 20 );
    cr_assert( my_strcmp( o.string, "Helloworldtestbanana" ) == true );
}

Test(set_8_string, set_string_t)
{
    op_string_t o = init_op_string();

    o.set_string(&o, 8, "AB", "CD", "EF", "GH", "IJ", "KL", "MN", "OP");
    cr_assert( o.mem_len == 2 * 8 );
    cr_assert( o.str_len == 2 * 8 );
    cr_assert( my_strcmp( o.string, "ABCDEFGHIJKLMNOP" ) == true );
}

Test(set_8_string_2_times, set_string_t)
{
    op_string_t o = init_op_string();

    o.set_string(&o, 8, "AB", "CD", "EF", "GH", "IJ", "KL", "MN", "OP");
    cr_assert( o.mem_len == 2 * 8 );
    cr_assert( o.str_len == 2 * 8 );
    cr_assert( my_strcmp( o.string, "ABCDEFGHIJKLMNOP" ) == true );

    o.set_string(&o, 8, "QRS", "TUV", "WXY", "Z01", "234", "567", "89;", ".?!");
    cr_assert( o.mem_len == 3 * 8 );
    cr_assert( o.str_len == 3 * 8 );
    cr_assert( my_strcmp( o.string, "QRSTUVWXYZ0123456789;.?!" ) != false );
}
