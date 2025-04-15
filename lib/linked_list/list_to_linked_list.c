/*
** EPITECH PROJECT, 2025
** B-PSU-200-PAR-2-1-minishell1-ariel.amriou
** File description:
** list_to_linked_list.c
*/

#include "linked_list.h"
#include "my.h"
#include <stdlib.h>

linked_list_t **list_to_linked_list(char **env)
{
    linked_list_t **head = malloc(sizeof(linked_list_t *));

    if (head == NULL)
        return NULL;
    *head = NULL;
    for (int i = 0; env[i] != NULL; i++)
        add_linked_list_rev(head, env[i]);
    return head;
}
