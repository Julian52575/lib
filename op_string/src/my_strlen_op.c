/*
** EPITECH PROJECT, 2023
** project_name
** File description:
** my_strlen_op
*/

int my_strlen_op(char *str)
{
    return (str[0] ? 1 + my_strlen_op(str + 1) : 0); 
}
