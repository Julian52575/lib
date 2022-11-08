/*
** EPITECH PROJECT, 2022
** printf_more_type
** File description:
** print more of the base of percent
*/

#include "../includes/my.h"
#include "../includes/my_printf.h"

int printf_expo_up(va_list ap, char *string, flag flags)
{
    double db = va_arg(ap, double);
    int a = 2 + ((flags).precision) + 4;
    ((flags).width) -= a;

    if ( ((flags).order) == 0)
        printf_width(ap, string, flags);

    my_put_exponential_up(db, ((flags).precision) );

    if ( ((flags).order) == 1)
        printf_width(ap, string, flags);

    return a;
}

int printf_expo(va_list ap, char *string, flag flags)
{
    double db = va_arg(ap, double);
    int a = 2 + ((flags).precision) + 4;
    ((flags).width) -= a;

    if ( ((flags).order) == 0)
        printf_width(ap, string, flags);

    my_put_exponential(db, ((flags).precision) );

    if ( ((flags).order) == 1)
        printf_width(ap, string, flags);

    return a;
}

int printf_o(va_list ap, char *string, flag flags)
{
    int tmp = va_arg(ap, int);
    int a = 0;
    ((flags).width) -= a;

    if ( ((flags).order) == 0)
        printf_width(ap, string, flags);

    my_put_octal(tmp);

    if ( ((flags).order) == 1)
        printf_width(ap, string, flags);
    return a;
}

int printf_double(va_list ap, char *string, flag flags)
{
    double db = va_arg(ap, double);
    int nb = db;
    int a = get_unit(nb) + ((flags).precision);
    ((flags).width) -= a;

    if ( ((flags).order) == 0)
        printf_width(ap, string, flags);

    my_put_double(db, ((flags).precision) );

    if ( ((flags).order) == 1)
        printf_width(ap, string, flags);
    return a;
}
