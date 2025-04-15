/*
** EPITECH PROJECT, 2025
** B-PSU-200-PAR-2-1-minishell1-ariel.amriou
** File description:
** linked_list_to_list.c
*/

#include "linked_list.h"
#include "my.h"

#include <stdlib.h>

char **linked_list_to_list(linked_list_t **head)
{
    linked_list_t *tmp = NULL;
    char **list = NULL;
    int count = 0;

    if (head == NULL)
        return NULL;
    tmp = *head;
    list = malloc(sizeof(char *) * (linked_list_len(head) + 1));
    if (list == NULL)
        return NULL;
    while (tmp != NULL) {
        list[count] = my_strdup(tmp->line);
        if (list[count] == NULL)
            return NULL;
        count++;
        tmp = tmp->next;
    }
    list[count] = NULL;
    return list;
}
