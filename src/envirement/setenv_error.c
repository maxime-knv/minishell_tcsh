/*
** EPITECH PROJECT, 2024
** minishel1
** File description:
** setenv_error.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "../../include/src.h"
#include "../../include/my.h"
#include "../../include/src.h"


int next(char **parsed_line)
{
    static const char first_env_charallowed[] =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    static const char env_charallowed[] =
    "1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz.";

    if (my_char_not_in(first_env_charallowed, parsed_line[1][0]) == 1) {
        mini_printf("setenv: Variable name must begin with a letter.\n");
        return SUCCESS;
    }
    for (int i = 1; parsed_line[1][i] != '\0'; i++) {
        if (my_char_not_in(env_charallowed, parsed_line[1][i]) == 1) {
            mini_printf("setenv: Variable name must contain"
            " alphanumeric characters.\n");
            return SUCCESS;
        }
    }
    return ERROR;
}

int setenv_error(int len, char **parsed_line, list_t *list)
{
    if (len == 1) {
        print_list(list);
        return SUCCESS;
    }
    if (len > 3) {
        mini_printf("setenv: Too many arguments.\n");
        return SUCCESS;
    }
    if (next(parsed_line) == SUCCESS)
        return SUCCESS;
    return ERROR;
}
