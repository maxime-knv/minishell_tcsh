/*
** EPITECH PROJECT, 2024
** my_strcat.c
** File description:
** zzz
*/
#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int k = 0;

    k = my_strlen(dest);
    while (src[i] != '\0') {
        dest[k + i] = src[i];
        i += 1;
    }
    dest[k + i] = '\0';
    return dest;
}
