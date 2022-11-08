/*
** EPITECH PROJECT, 2022
** printf_width_type
** File description:
** analyse width ans type
*/

#include "../includes/my.h"
#include "../includes/my_printf.h"

int get_precision(char *string, flag flags)
{
    int j = 0;
    char *numbers = malloc(my_strlen(string) + 1);
    for (int i = 0; string[i] != '\0'; i++) {
        if (48 <= string[i] && string[i] <= 57)
            numbers[j++] = string[i];
    }
    int precision = my_str_to_int(numbers);
    return precision;
}

flag get_width(char *string, flag flags)
{
    ((flags).precision) = 6;
    char *numbers = malloc(my_strlen(string) + 1);
    int j = 0;
    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] == '.') {
            ((flags).precision) = get_precision(string + i, flags);
            break;
        }
        if (48 <= string[i] && string[i] <= 57)
            numbers[j++] = string[i];
    }
    numbers[j] = '\0';
    ((flags).width) = my_str_to_int(numbers);
    return flags;
}

int printf_width(va_list ap, char *string, flag flags)
{
    int len = my_strlen(string);
    if ( ((flags).space) = '*')
        ((flags).space) = ' ';

    for (int x = 0; x < ((flags).width); x++) {
        my_putchar( ((flags).space) );
    }
    return ((flags).width);
}

int printf_type(va_list ap, char *string, flag flags)
{
    int len = my_strlen(string);
    char type = string[len - 1];
    int (* ptr[200]) (va_list, char *, flag flags);
    ptr['c'] = &printf_char;
    ptr['d'] = &printf_int;
    ptr['i'] = &printf_int;
    ptr['s'] = &printf_string;
    ptr['n'] = &printf_n;
    ptr['f'] = &printf_double;
    ptr['F'] = &printf_double;
    ptr['e'] = &printf_expo;
    ptr['E'] = &printf_expo_up;
    ptr['o'] = &printf_o;
    ptr['u'] = &printf_u;
    ptr['b'] = &printf_b;
    int a = (* ptr[type])(ap, string, flags);
    return a;
}
