/*
** EPITECH PROJECT, 2024
** minishel2
** File description:
** is_semilicon.c
*/

#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/wait.h>
#include "../include/my.h"
#include <stdbool.h>



bool is_semilicon(char const *str)
{
    if (my_strcmp(str, ";") == 0)
        return true;
    else
        return false;
}
