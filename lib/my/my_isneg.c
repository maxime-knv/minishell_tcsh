/*
** EPITECH PROJECT, 2024
** my_isneg
** File description:
** N if negative, P if positive
*/

#include <unistd.h>
#include <stdio.h>
#include "my.h"

void my_isneg(int n)
{
    char P = 80;
    char N = 78;

    if (n >= 0) {
        my_putchar(P);
    } else {
        my_putchar(N);
    }
}
