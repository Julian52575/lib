/*
** EPITECH PROJECT, 2022
** my is alpha
** File description:
** are the 2str in alphabetical order ?
*/

//return 1 if the 2 str are in alphabetical order, 0 if not.
int my_is_alpha(char *str1, char *str2)
{
    if (str1[0] == '\0') {
        return 1;
    } else if (str2[0] == '\0') {
        return 0;
    }

    if (65 <= str1[0] && str1[0] <= 90) {
        str1[0] += 32;
    } else if (65 <= str2[0] && str2[0] <= 90) {
        str2[0] += 32;
    }

    if (str1[0] > str2[0]) return 0;
    if (str1[0] == str2[0]) return my_is_alpha(str1 + 1, str2 + 1);
    return 1;
}
