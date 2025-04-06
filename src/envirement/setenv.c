/*
** EPITECH PROJECT, 2024
** minishel1
** File description:
** setenv.c
*/


#include <stdlib.h>
#include <stdio.h>
#include "../include/src.h"
#include "../include/my.h"
#include "src.h"

int set_env(list_t **head, char const *name, char *val)
{
    list_t *tmp = *head;
    list_t *new_node = create_val(name, val);
    char **arr = NULL;

    if (new_node == NULL)
        return ERROR;
    while (tmp != NULL && tmp->next != NULL) {
        arr = my_str_to_word_array(tmp->next->line, '=');
        if (my_strcmp(arr[0], name) == 0) {
            tmp->next->line = my_mulcat(3, name, "=", val);
            break;
        }
        tmp = tmp->next;
    }
    if (tmp && tmp->next == NULL) {
        tmp->next = new_node;
    } else if (tmp == NULL) {
        *head = new_node;
    }
    return 0;
}
