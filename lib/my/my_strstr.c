/*
** EPITECH PROJECT, 2024
** my_strstr
** File description:
** search to_find in str and return from to_find to the end of str
*/

#include "my.h"

static void condi(char *str, char const *to_find, int *i, int *found)
{
    int k = *i;

    for (int j = 0; j < my_strlen(to_find); j++){
        *found = 1;
        if (str[k] != to_find[j]){
            *found = 0;
            break;
        }
    k++;
    }
}

char *my_strstr(char *str, char const *to_find)
{
    int found = 1;

    for (int i = 0; i < my_strlen(str); i++) {
        condi(str, to_find, &i, &found);
        if (found != 0){
            return &str[i];
        }
    }
    return 0;
}
