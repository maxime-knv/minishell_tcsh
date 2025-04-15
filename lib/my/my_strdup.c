/*
** EPITECH PROJECT, 2024
** my_strdup
** File description:
** dup a string
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(char const *src)
{
    int len = my_strlen(src);
    char *dup = NULL;

    if (src == NULL)
        return NULL;
    dup = malloc(len + 1);
    if (dup == NULL)
        return NULL;
    for (int i = 0; src[i] != '\0'; i++)
        dup[i] = src[i];
    dup[len] = '\0';
    return dup;
}
