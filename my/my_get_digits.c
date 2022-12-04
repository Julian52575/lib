/*
** EPITECH PROJECT, 2022
** get_digit
** File description:
** get the Xth digit of the number passed as a parameter
*/

int get_1st_digit(int nb)
{
    printf("%d\n", nb / 100);
    return (nb / 100);
}

int get_2nd_digit(int nb)
{
    printf("%d\n", (nb / 10) % 10);
    return( (nb / 10) % 10);
}

int get_3rd_digit(int nb)
{
    printf("%d\n", nb % 10);
    return (nb % 10);
}
