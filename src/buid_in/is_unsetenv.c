/*
** EPITECH PROJECT, 2024
** minishel2
** File description:
** is_unsetenv.c
*/

#include <stdbool.h>
#include "my.h"

bool is_unsetenv(char const *line)
{
    if (my_strcmp(line, "unsetenv") == 0)
        return true;
    return false;
}
