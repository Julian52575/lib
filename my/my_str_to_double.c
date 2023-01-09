/*
** EPITECH PROJECT, 2022
** Str to double
** File description:
** no more str
*/
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

double my_str_to_double(char *str)
{
    char *decimal = malloc( sizeof(char) * my_strlen(str)) ;
    int i = 0;
    int j = 0;
    for (; (str[i] != '.') && (str[i] != ',') && (str[i] != '\0'); i++);
    for (;str[i] != '\0'; i++ ) {
        decimal[j++] = str[i];
        str[i] = '\0';
    }
    decimal++;
    double top_bread = my_str_to_int(str);
    double bottom_bread = my_str_to_int(decimal);
    bottom_bread = bottom_bread /
    my_compute_power_rec(10, my_get_unit(bottom_bread));
    return top_bread + bottom_bread;
}
