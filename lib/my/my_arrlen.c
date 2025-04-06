/*
** EPITECH PROJECT, 2024
** minishel1
** File description:
** my_arrlen.c
*/

#include <stddef.h>
#include "my.h"

int my_arrlen(char **arr)
{
    int i = 0;

    while (arr[i] != NULL) {
        i++;
    }
    return i;
}
