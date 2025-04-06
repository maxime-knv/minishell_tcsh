/*
** EPITECH PROJECT, 2024
** minishel2
** File description:
** get_new_str_from_arr.c
*/

#include "my.h"
#include "my_struct.h"

char *get_new_str_from_arr(char **arr, int beggin, int end)
{
    char *new = NULL;
    int nb = 0;

    if (end - beggin - 1 == 0)
        return arr[beggin];
    if (beggin != 0) {
        end--;
        beggin++;
    } else
        end--;
    for (int i = beggin; i <= end; i++)
        nb += my_strlen(arr[i]);
    new = malloc(sizeof(char) * nb + 3);
    new[0] = '\0';
    for (int i = beggin; i <= end; i++) {
        new = my_strcat(new, arr[i]);
        if (i != end)
            new = my_strcat(new, " ");
    }
    return new;
}
