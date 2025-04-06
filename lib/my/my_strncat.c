/*
** EPITECH PROJECT, 2024
** my_strncat.c
** File description:
** zzz
*/
#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int k = 0;

    k = my_strlen(dest);
    if (nb <= 0) {
        return dest;
    }
    while (src[i] != '\0' && i < nb) {
        dest[k + i] = src[i];
        i += 1;
    }
    return dest;
}
