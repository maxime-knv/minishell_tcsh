/*
** EPITECH PROJECT, 2025
** B-PSU-200-PAR-2-1-minishell1-ariel.amriou
** File description:
** delete_linked_list.c
*/

#include "linked_list.h"

#include <stdlib.h>

void delete_linked_list(linked_list_t **head)
{
    linked_list_t *tmp = NULL;
    linked_list_t *node = NULL;

    if (head == NULL)
        return;
    node = *head;
    while (node != NULL) {
        tmp = node->next;
        free(node->line);
        free(node);
        node = tmp;
    }
    free(head);
    head = NULL;
}
