/*
** EPITECH PROJECT, 2024
** minishel2
** File description:
** is_setenv.c
*/

#include <stdbool.h>
#include "my.h"

bool is_setenv(char const *line)
{
    if (my_strcmp(line, "setenv") == 0)
        return true;
    return false;
}
