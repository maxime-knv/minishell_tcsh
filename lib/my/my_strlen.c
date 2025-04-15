/*
** EPITECH PROJECT, 2024
** my_strlen
** File description:
** return the lenght of str
*/

#include <stddef.h>

int my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL)
        return 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}
