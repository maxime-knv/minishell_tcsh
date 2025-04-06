/*
** EPITECH PROJECT, 2025
** my_strndup.c
** File description:
** strndup
*/

#include <stdlib.h>

#include "my.h"

char *my_strndup(const char *str, int n)
{
    char *dest;
    int i = 0;

    if (n > my_strlen(str))
        n = my_strlen(str);
    dest = malloc(sizeof(char) * (n + 1));
    while (i < n) {
        dest[i] = str[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
