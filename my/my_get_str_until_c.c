/*
** EPITECH PROJECT, 2022
** my get str until c
** File description:
** return a string from beggining to 2nd character passed as a parameter
*/

#include <unistd.h>
#include <my.h>

char *my_get_str_until_c(char *str, char end)
{
    int i = 0;
    for (; str[i] && str[i] != end; ++i);
    char *buffer = malloc( (sizeof(char) * i) + 1);

    for (int j = 0; j < i; j++) buffer[j] = str[j];
    buffer[i] = '\0';

    return buffer;
}
