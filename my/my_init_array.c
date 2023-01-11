/*
** EPITECH PROJECT, 2022
** my_init_array
** File description:
** initialize an array of height y and width x
*/
#include <stdlib.h>
#include <stdio.h>

char **my_init_array(int len_y, int len_x)
{
    int i = 0;
    char **array = malloc( (sizeof(char*) * len_y) + 1);
    for (; i < len_y; i++) array[i] = malloc(sizeof(char) * len_x);
    array[i] = malloc(sizeof(char));
    array[i][0] = '\0';
    return array;
}
