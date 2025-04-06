/*
** EPITECH PROJECT, 2024
** minishel1
** File description:
** my_char_not_in.c
*/

#include "src.h"

int my_char_not_in(char const *str, char c)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            return SUCSESS;
    }
    return 1;
}
