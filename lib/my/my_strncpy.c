/*
** EPITECH PROJECT, 2024
** my_strcpy
** File description:
** copy the string to into another
*/

#include <stddef.h>
#include <stdio.h>

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    if (src[i] == '\0') {
        dest = '\0';
        return dest;
    }
    for (i = 0; i < n; i++) {
        dest[i] = src[i];
    }
    while (dest[i] != '\0')
        dest[i] = '\0';
    return dest;
}
