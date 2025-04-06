/*
** EPITECH PROJECT, 2024
** minishel1
** File description:
** len_linked_list.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "../../include/src.h"
#include "../../include/src.h"

int len_linked_list(list_t *head)
{
    list_t *tmp = head;
    int i = 0;

    if (tmp == NULL)
        return 0;
    while (tmp != NULL) {
        i++;
        tmp = tmp->next;
    }
    return i;
}
