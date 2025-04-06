/*
** EPITECH PROJECT, 2024
** minishel2
** File description:
** get_build.c
*/

#include "my_struct.h"

int get_buid(char *value)
{
    for (int i = 0; build_in_list[i] != NULL; i++){
        if ((*build_in_list[i])(value)) {
            return i;
        }
    }
    return OTHER;
}
