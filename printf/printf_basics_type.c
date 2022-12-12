/*
** EPITECH PROJECT, 2022
** printf_basics_type
** File description:
** print the base of percent
*/

#include "../includes/my.h"
#include "../includes/my_printf.h"

int printf_int(va_list ap, char *string, flag flags)
{
    if ( ((flags).plus) == 1 &&
        ( ((flags).space) == ' ' || ((flags).space) == '*') ) {
        my_putchar('+');
        ((flags).width) -= 1;
    }
    int tmp = va_arg(ap, int);
    int a = get_unit(tmp);
    ((flags).width) -= a;

    if ( ((flags).order) == 0)
        printf_width(ap, string, flags);

    my_put_nbr(tmp);

    if ( ((flags).order) == 1)
        printf_width(ap, string, flags);
    return a + ((flags).width);
}

int printf_char(va_list ap, char *string, flag flags)
{
    char tmp = (char) va_arg(ap, int);
    ((flags).width) -= 1;

    if ( ((flags).order) == 0)
        printf_width(ap, string, flags);

    my_putchar(tmp);

    if ( ((flags).order) == 1)
        printf_width(ap, string, flags);
    return 1 + ((flags).width);
}

int printf_string(va_list ap, char *string, flag flags)
{
    char *tmp = va_arg(ap, char *);
    int len = my_strlen(tmp);
    ((flags).width) -= len;

    if ( ((flags).order) == 0)
        printf_width(ap, string, flags);

    write(1, tmp, len + 1);

    if ( ((flags).order) == 1)
        printf_width(ap, string, flags);
    return ((flags).width) + len;
}

int printf_n(va_list ap, char *string, flag flags)
{
    int *tmp = va_arg(ap, int*);
    *tmp = ((flags).position);
    return 0;
}
