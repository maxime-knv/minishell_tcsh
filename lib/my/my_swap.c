/*
** EPITECH PROJECT, 2024
** my_swap
** File description:
** swaps content of two integers
*/
#include <stdio.h>

void my_swap(int *a, int *b)
{
    int c;
    int *ptrc = &c;

    *ptrc = *a;
    *a = *b;
    *b = *ptrc;
}
