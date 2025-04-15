/*
** EPITECH PROJECT, 2024
** my_strcat
** File description:
** function that concatenates two strings
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = my_strlen(dest);
    int j;

    for (j = 0; src[j] != '\0' && j < nb; j++) {
        dest[i + j] = src[j];
    }
    dest[i + j + 1] = '\0';
    return dest;
}
