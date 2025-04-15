/*
** EPITECH PROJECT, 2024
** my_swap
** File description:
** swap char a with char b
*/

#include "my.h"

void my_swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}
