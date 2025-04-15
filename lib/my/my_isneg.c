/*
** EPITECH PROJECT, 2024
** my_isneg
** File description:
** print N if n is negative, P if not
*/

#include "my.h"

void my_isneg(int n)
{
    if (n < 0) {
        my_putchar('N');
    } else {
        my_putchar('P');
    }
}
