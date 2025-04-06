/*
** EPITECH PROJECT, 2024
** my_str_to word_array
** File description:
** tqt
*/
#include <stdlib.h>
#include "my.h"
#include <stdio.h>
#include <string.h>

int is_return_to_line(char const str, char c)
{
    if ((str == c) || str == '\t' || str == '\n')
        return 0;
    else
        return 1;
}

int cont_words(char const *str, char c)
{
    int is_word = 0;
    int nb = 0;

    while (*str != '\0') {
        if (is_return_to_line(*str, c) == 1)
            is_word = 1;
        if (is_return_to_line(*str, c) == 0 && is_word == 1) {
                nb += 1;
                is_word = 0;
        }
        str += 1;
    }
    if (is_word == 1)
        nb += 1;
    return nb;
}

int cont_letters(char const *str, char c)
{
    int nb = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (is_return_to_line(str[i], c) == 0)
            return nb;
        nb += 1;
    }
    return nb;
}

char **my_str_to_word_array(char const *str, char c)
{
    int slen = 0;
    int wrds = cont_words(str, c);
    char **arr = (char **)malloc(sizeof(char *) * (wrds + 1));
    int i = 0;

    while (*str != '\0') {
        if (is_return_to_line(*str, c)) {
            slen = cont_letters(str, c);
            arr[i] = malloc(sizeof(char) * (slen + 1));
            arr[i][slen] = '\0';
            my_strncpy(arr[i], str, slen);
            str += slen;
            i += 1;
        } else {
            str += 1;
        }
    }
    arr[wrds] = NULL;
    return arr;
}
