/*
** EPITECH PROJECT, 2023
** project_name
** File description:
** set_string
*/

#include "op_string.h"

static void allocate_memory(struct op_string_s *o, int size)
{
    if ( o->string )
        free(o->string);
    o->string = malloc(sizeof(char) * (size + 1));
    o->mem_len = size;
}

static void fill_lenght_array(int number_of_string,
        int *lenght_array, va_list ap)
{
    va_list tmp = { 0 };
    char *current = NULL;

    va_copy(tmp, ap);
    for ( int i = 0; i < number_of_string; i++ ) {
        current = va_arg( tmp, char * );
        lenght_array[i] = my_strlen_op( current );
    }
}

static int copy_string(struct op_string_s *o, char *str, int current_postion)
{
    int i = 0;

    for (; str[ i ]; i++) {
        o->string[ current_postion + i ] = str[ i ];
    }
    return current_postion + i;
}

//set_string(o, 3, "a", "b", "c");
void set_string_op_string(struct op_string_s *o, int number_of_string, ...)
{
    va_list ap = { 0 };
    int *lenght_array = malloc(sizeof(int) * (number_of_string + 1));
    int total_lenght = 0;
    int current_postion = 0;
    char *current_str = NULL;

    va_start(ap, number_of_string);
    fill_lenght_array(number_of_string, lenght_array, ap);

    for (int i = 0; i < number_of_string; i++)
        total_lenght += lenght_array[ i ];

    if ( o->mem_len < total_lenght )
        allocate_memory( o, total_lenght );
    for (int y = 0; y < number_of_string; y++) {
        current_str = va_arg( ap, char * );
        current_postion = copy_string( o, current_str, current_postion );
    }
    o->str_len = total_lenght;
    free(lenght_array);
}
