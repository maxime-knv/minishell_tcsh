/*
** EPITECH PROJECT, 2024
** minishel2
** File description:
** get_priority_index.c
*/

#include "my.h"
#include "src.h"
#include "my_struct.h"

int get_priority_index(char **parsed_input)
{
    int index = 0;
    int tmp = NONE;
    int ret = 0;

    for (int i = 0; parsed_input[i] != NULL; i++) {
        index = get_sep(parsed_input[i]);
        if (tmp > index) {
            tmp = index;
            ret = i;
        }
    }
    return ret;
}
