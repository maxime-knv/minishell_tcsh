/*
** EPITECH PROJECT, 2024
** minishel1
** File description:
** my_getenv.c
*/


#include <stddef.h>
#include "my.h"

char *my_getenv(char *name, char **env)
{
    int i = 0;
    char **dest = NULL;

    while (env[i] != NULL) {
        if (my_is_in(env[i], name) == 0) {
            break;
        }
        i++;
    }
    if (i == my_arrlen(env))
        return "";
    dest = my_str_to_word_array(env[i], '=');
    return dest[1];
}
