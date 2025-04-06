/*
** EPITECH PROJECT, 2024
** minishel1
** File description:
** create_val.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "src.h"
#include "my.h"
#include "src.h"

list_t *create_val(char const *name, char *val)
{
    list_t *new_node = malloc(sizeof(list_t));
    unsigned long size = 0;

    if (new_node == NULL)
        return NULL;
    if (val == NULL)
        val = my_strdup("");
    size = sizeof(char) * (my_strlen(name) + my_strlen(val) + 2);
    new_node->line = malloc(size);
    new_node->line = my_mulcat(3, name, "=", val);
    new_node->next = NULL;
    return new_node;
}
