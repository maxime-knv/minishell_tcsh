/*
** EPITECH PROJECT, 2025
** B-PSU-200-PAR-2-1-minishell1-ariel.amriou
** File description:
** linked_list_len.c
*/

#include "linked_list.h"
#include <stddef.h>

int linked_list_len(linked_list_t **head)
{
    linked_list_t *tmp = NULL;
    int count = 0;

    if (head == NULL)
        return 0;
    tmp = *head;
    while (tmp != NULL) {
        count++;
        tmp = tmp->next;
    }
    return count;
}
