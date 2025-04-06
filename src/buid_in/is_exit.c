/*
** EPITECH PROJECT, 2024
** minishel2
** File description:
** is_exit.c
*/

#include <stdbool.h>
#include "my.h"

bool is_exit(char const *line)
{
    if (my_strcmp(line, "exit") == 0)
        return true;
    return false;
}
