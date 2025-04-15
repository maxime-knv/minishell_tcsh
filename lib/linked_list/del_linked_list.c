/*
** EPITECH PROJECT, 2024
** B-CPE-110-PAR-1-1-organized-ariel.amriou
** File description:
** del.c
*/

#include <stdlib.h>
#include <string.h>
#include "linked_list.h"
#include "my.h"

static void relink_node(linked_list_t *node1, linked_list_t *node2)
{
    linked_list_t *tmp = NULL;

    tmp = node1->next;
    node1->next = node2->next;
    free(tmp->line);
    free(tmp);
}

static void relink_first(linked_list_t **head)
{
    linked_list_t *tmp = NULL;

    tmp = (*head);
    (*head) = (*head)->next;
    free(tmp->line);
    free(tmp);
}

static int check_first(char *var, linked_list_t **head, linked_list_t *tmp)
{
    char *line = my_strdup(tmp->line);
    char *line_var = NULL;

    if (line == NULL)
        return 0;
    line_var = strtok_r(line, "=", &line);
    if (my_strcmp(line_var, var) == 0) {
        free(line_var);
        relink_first(head);
        return 1;
    }
    free(line_var);
    return 0;
}

static int check_other(char *var, linked_list_t *tmp)
{
    char *line = my_strdup(tmp->next->line);
    char *line_var = NULL;

    if (line == NULL)
        return 0;
    line_var = strtok_r(line, "=", &line);
    if (my_strcmp(line_var, var) == 0) {
        free(line_var);
        relink_node(tmp, tmp->next);
        return 1;
    }
    free(line_var);
    return 0;
}

int del_linked_list(linked_list_t **head, char *var)
{
    linked_list_t *tmp = NULL;

    if (head == NULL)
        return 84;
    tmp = *head;
    if (tmp == NULL)
        return 0;
    if (check_first(var, head, tmp) == 1)
        return 1;
    while (tmp != NULL && tmp->next != NULL) {
        if (check_other(var, tmp) == 1)
            return 1;
        tmp = tmp->next;
    }
    return 0;
}
