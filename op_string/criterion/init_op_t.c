/*
** EPITECH PROJECT, 2023
** project_name
** File description:
** init_op_t
*/

#include "op_string.h"

Test(init_empty_str, init_testing) {
    op_string_t o = init_op_string(  );

    cr_assert( o.string == NULL );
    cr_assert( o.str_len == 0 );
    cr_assert( o.mem_len == 0 );
}

