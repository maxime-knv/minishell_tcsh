/*
** EPITECH PROJECT, 2024
** minishel2
** File description:
** get_sep.c
*/

#include "my_struct.h"

int get_sep(char *value)
{
    for (int i = 0; sep_func_list[i] != NULL; i++){
        if ((*sep_func_list[i])(value)) {
            return i;
        }
    }
    return NONE;
}
