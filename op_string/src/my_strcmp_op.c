/*
** EPITECH PROJECT, 2023
** project_name
** File description:
** my_strcmp_op
*/

#include <stdbool.h>

bool my_strcmp(char *s1, char *s2)
{
    for (int i = 0; s1 && s2 && s1[i] && s2[i]; i++) {
        if ( s1[i] != s2[i] )
            return false;
    }
    if (!s1 && s2)
        return false;
    else if (s1 && !s2)
        return false;
    return true;
}
