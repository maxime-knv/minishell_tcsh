/*
** EPITECH PROJECT, 2024
** minishel2
** File description:
** is_one_right.c
*/

#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdbool.h>
#include "../include/my.h"

bool is_one_right(char const *str)
{
    if (my_strcmp(str, ">") == 0)
        return true;
    else
        return false;
}
