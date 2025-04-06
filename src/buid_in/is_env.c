/*
** EPITECH PROJECT, 2024
** minishel2
** File description:
** is_env.c
*/

#include <stdbool.h>
#include "my.h"

bool is_env(char const *line)
{
    if (my_strcmp(line, "env") == 0)
        return true;
    return false;
}
