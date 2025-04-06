/*
** EPITECH PROJECT, 2024
** my_revstr.c
** File description:
** task 03 day 02
*/
#include "my.h"

char *my_revstr(char *str)
{
    int i = 0;
    int j = my_strlen(str) - 1;
    char c = 0;

    my_strlen(str);
    while (i <= j) {
        c = str[i];
        str[i] = str[j];
        str[j] = c;
        i = i + 1;
        j = j - 1;
    }
    return str;
}
