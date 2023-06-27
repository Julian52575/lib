/*
** EPITECH PROJECT, 2022
** get_unit
** File description:
** lenth of an int
*/

int my_get_unit(int nb)
{
    if (nb >= 0) {
        if (nb == 0)
            return 0;
        if (nb <= 9)
            return 1;
        else
            return 1 + my_get_unit(nb / 10);
    } else {
        return my_get_unit(nb * -1);
    }
}
