/*
** EPITECH PROJECT, 2024
** minishel2
** File description:
** is_cd.c
*/

#include <stdbool.h>
#include "my.h"

bool is_cd(char const *line)
{
    if (my_strcmp(line, "cd") == 0)
        return true;
    return false;
}
