/*
** EPITECH PROJECT, 2024
** B-CPE-110-PAR-1-1-organized-ariel.amriou
** File description:
** add.c
*/

#include <stdlib.h>
#include <unistd.h>
#include "linked_list.h"
#include "my.h"

static int add_first(linked_list_t **head, char *line)
{
    *head = malloc(sizeof(linked_list_t));
    if (*head == NULL)
        return 84;
    (*head)->next = NULL;
    (*head)->line = my_strdup(line);
    if ((*head)->line == NULL)
        return 84;
    return 0;
}

int add_linked_list_rev(linked_list_t **head, char *line)
{
    linked_list_t *new = NULL;
    linked_list_t *tmp = NULL;

    if (head == NULL || line == NULL)
        return 84;
    if (*head == NULL)
        return add_first(head, line);
    tmp = *head;
    new = malloc(sizeof(linked_list_t));
    if (new == NULL)
        return 84;
    while (tmp->next != NULL)
        tmp = tmp->next;
    new->next = NULL;
    new->line = my_strdup(line);
    if (new->line == NULL)
        return 84;
    tmp->next = new;
    return 0;
}

int add_linked_list(linked_list_t **head, char *line)
{
    linked_list_t *new = malloc(sizeof(linked_list_t));

    if (new == NULL)
        return 84;
    new->next = *head;
    new->line = my_strdup(line);
    *head = new;
    return 0;
}
