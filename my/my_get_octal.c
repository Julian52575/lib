/*
** EPITECH PROJECT, 2022
** my_get_octal
** File description:
** convert decimal to octal w/out printing
*/

#include "my.h"

unsigned int my_put_octal(unsigned int nb)
{
    if (nb > 7)
        my_put_octal(nb / 8);
    my_put_nbr(nb % 8);
    nb = nb % 8;
    return (nb);
}
