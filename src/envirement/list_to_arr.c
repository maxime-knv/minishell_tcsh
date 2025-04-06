/*
** EPITECH PROJECT, 2024
** minishel1
** File description:
** list_to_arr.c
*/
#include <stdlib.h>
#include <stdio.h>
#include "../../include/src.h"
#include "../../include/src.h"

char **list_to_arr(list_t *head)
{
    list_t *tmp = head;
    char **arr = NULL;
    int i = 0;
    int size = len_linked_list(head);

    arr = malloc(sizeof(char *) * (size + 4));
    if (tmp == NULL)
        return 0;
    while (tmp != NULL) {
        arr[i] = tmp->line;
        i++;
        tmp = tmp->next;
    }
    arr[i] = NULL;
    return arr;
}
