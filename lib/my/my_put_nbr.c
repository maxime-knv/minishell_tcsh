/*
** EPITECH PROJECT, 2024
** my_put_nbr
** File description:
** zzz
*/

#include <stdlib.h>

#include "my.h"
#include <unistd.h>

int my_put_nbr(int nb)
{
    if (nb == -2147483648)
        write(1, "-2147483648", 11);
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    if (nb >= 10) {
        my_put_nbr(nb / 10);
    }
    my_putchar(nb % 10 + '0');
    return 0;
}
