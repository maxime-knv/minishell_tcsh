/*
** EPITECH PROJECT, 2024
** minishel2
** File description:
** cut_array.c
*/

#include "my.h"
#include "my_struct.h"

char **cut_array(char **arr, int i, int j)
{
    char **new_arr = malloc(sizeof(char *) * (j - i + 1));
    int id = 0;

    for (int index = i; index < j; index++) {
        new_arr[id] = my_strndup(arr[index], my_strlen(arr[index]));
        id += 1;
    }
    new_arr[id] = NULL;
    return new_arr;
}
