/*
** EPITECH PROJECT, 2024
** my_strcmp
** File description:
** compare the ascii value of each char in s1 and s2
*/

#include <stddef.h>
#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    if (s1 == NULL || s2 == NULL)
        return EPI_ERROR;
    while (s1[i] != '\0' || s2[i] != '\0') {
        if (s1[i] < s2[i])
            return -1;
        if (s1[i] > s2[i])
            return 1;
        i++;
    }
    if (s1[i] < s2[i])
        return -1;
    if (s1[i] > s2[i])
        return 1;
    return 0;
}
