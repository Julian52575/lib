/*
** EPITECH PROJECT, 2022
** printf_even_more_type
** File description:
** print even more of the base of percent
*/

#include "../includes/my.h"
#include "../includes/my_printf.h"

int printf_u(va_list ap, char *string, flag flags)
{
    int tmp = va_arg(ap, int);
    int a = get_unit(tmp);
    ((flags).width) -= a;

    if ( ((flags).order) == 0)
        printf_width(ap, string, flags);

    my_unsigned_int(tmp);

    if ( ((flags).order) == 1)
        printf_width(ap, string, flags);
    return a;           ;
}

int printf_b(va_list ap, char *string, flag flags)
{
    int tmp = va_arg(ap, int);
    int a = get_unit(tmp);
    ((flags).width) -= a;

    if ( ((flags).order) == 0)
        printf_width(ap, string, flags);

    my_put_binary(tmp);

    if ( ((flags).order) == 1)
        printf_width(ap, string, flags);

    return get_unit(tmp);
}
