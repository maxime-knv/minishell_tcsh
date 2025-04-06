/*
** EPITECH PROJECT, 2024
** minishel2
** File description:
** is_pipe.c
*/

#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/wait.h>
#include "../include/my.h"


bool is_pipe(char const *str)
{
    if (my_strcmp(str, "|") == 0)
        return true;
    else
        return false;
}
