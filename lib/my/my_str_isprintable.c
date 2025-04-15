/*
** EPITECH PROJECT, 2024
** my_str_isprintable
** File description:
** c
*/

#include "my.h"

int my_str_isprintable(char const *str)
{
    int len = my_strlen(str);

    if (len == 0) {
        return 1;
    }
    for (int i = 0; i < len; i++) {
        if (str[i] < '!' || str[i] > '~') {
            return 0;
        }
    }
    return 1;
}
