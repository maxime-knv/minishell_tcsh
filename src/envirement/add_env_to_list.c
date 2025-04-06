/*
** EPITECH PROJECT, 2024
** minishel1
** File description:
** add_env_to_list.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "src.h"
#include "my.h"
#include "src.h"

int add_env_to_list(list_t **head, char **env)
{
    list_t *new_node = NULL;
    list_t *tmp = NULL;

    if (env[0] == NULL)
        return ERROR;
    new_node = create_node(env[0]);
    *head = new_node;
    for (int i = 1; env[i] != NULL; i++) {
        new_node = create_node(env[i]);
        if (new_node == NULL)
            return SUCSESS;
        if (head == NULL)
            *head = new_node;
        tmp = *head;
        while (tmp != NULL && tmp->next != NULL) {
            tmp = (tmp)->next;
        }
        (tmp)->next = new_node;
    }
    return SUCSESS;
}
