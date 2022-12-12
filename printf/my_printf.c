/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** call fonction
*/

#include "../includes/my_printf.h"
#include "../includes/my.h"

int my_printf(const char *format, ...)
{
    va_list ap;
    va_start(ap, format);
    flag flags = {0, 0};
    for (; format[ ((flags).i) ] != '\0' ; ((flags).i)++) {
        if (format[ ((flags).i) ] == '\n') {
            my_putchar('\n');
            ((flags).count) += 1;
            continue;
        } if (format[ ((flags).i) ] != '%') {
            my_putchar(format[ ((flags).i) ]);
            ((flags).count) += 1;
            continue;
        } if (format[ ((flags).i) ] == '%' &&
            format[ ((flags).i) + 1] == '%') {
            my_putchar('%');
            ((flags).count) += 1;
            ((flags).i)++;
            continue;
        } flags = printf_percent(ap, format, flags);
    } return ((flags).count);
}
