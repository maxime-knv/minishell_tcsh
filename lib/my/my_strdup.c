/*
** EPITECH PROJECT, 2024
** my_strdup.c
** File description:
** task 01 day 08
*/

#include "my.h"
#include <stdlib.h>

char *my_strdup(char const *src)
{
    char *dest;
    int i = 0;

    i = my_strlen(src);
    dest = malloc(sizeof(char) * (i + 1));
    my_strcpy(dest, src);
    return dest;
}
