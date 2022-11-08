/*
** EPITECH PROJECT, 2022
** printf_analyze
** File description:
** ananlyse strings
*/

#include "../includes/my.h"
#include "../includes/my_printf.h"

flag check_flags(flag flags, char c)
{
    if (c == '-') {
        ((flags).order) = 1;
        ((flags).space) = '*';
    }
    if (c == '0' && ((flags).space) != '*')
        ((flags).space) = '0';
    if (c == '+')
        ((flags).plus) = 1;
    if (c == ' ')
        ((flags).blank) = 1;
    if (c == '#')
        ((flags).hashtag) = 1;
    return flags;
}

flag printf_flags(char *string, flag flags)
{
    flags = get_width(string, flags);
    ((flags).nb) = ((flags).width);
    if ( ((flags).blank) == 1 && ((flags).plus) == 0) {
        my_putchar(' ');
        ((flags).width) -= 1;
        ((flags).blank) = 0;
    }
    if ( ((flags).space) == '0' && ((flags).plus) == 1) {
        my_putchar('+');
        ((flags).width) -= 1;
    }
    return flags;
}

int printf_analyze(va_list ap, char* string, flag flags)
{
    for (int v = 0; string[v] != '\0' &&
        string[v] != '.' &&
        string[v] < 49 || string[v] > 57;
        v++) {
            flags = check_flags(flags, string[v]);
    }
    flags = printf_flags(string, flags);
    printf_type(ap, string, flags);
    return ((flags).nb);
}

int check_valid_type(va_list ap, char t)
{
    char flag_list[] = "-+0 #123456789.hlL\0";
    if (t == 'g' || t == 'G' || t == 'u' || t == 's' || t == 'u')
        return 2;
    if (t == 'e' || t == 'E' || t == 'f' || t == 'F' || t == 'n')
        return 3;
    if (t == 'o' || t == 'x' || t == 'X' || t == 'i' || t == 'd')
        return 4;
    if (t == 'c' || t == 'b')
        return 5;
    for (int i = 0; flag_list[i] != '\0'; i++) {
        if (flag_list[i] == t)
            return 1;
    }
    return -1;
}

flag printf_percent(va_list ap, const char* format, flag flags)
{
    char *string = malloc(sizeof(char) * (my_strlen(format) - ((flags).i) ));
    int j = 0;
    ((flags).position) = ((flags).i);
    for (int check = 1; check > 0; 1) {
        string[j++] = format[ ((flags).i)++];
        check = check_valid_type(ap, format[ ((flags).i) ]);
        if (check > 1) {
            string[j] = format[ ((flags).i) ];
            string[j + 1] = '\0';
            ((flags).count) += printf_analyze(ap, string, flags);
            return flags;
        }
        if (check == -1 || format[ ((flags).i) ] == '\0') {
            ((flags).i) = ((flags).position);
            return flags;
        }
    }
}
