/*
** EPITECH PROJECT, 2024
** minishel1
** File description:
** free_all.c
*/

#include <stddef.h>
#include <stdlib.h>

void free_all(char **array)
{
    if (array == NULL)
        return;
    for (int i = 0; array[i] != NULL; i++) {
        free(array[i]);
    }
    free(array);
    return;
}
