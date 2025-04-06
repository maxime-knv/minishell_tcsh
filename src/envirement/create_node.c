/*
** EPITECH PROJECT, 2024
** minishel1
** File description:
** create_node.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "src.h"
#include "my.h"
#include "src.h"


list_t *create_node(char *line)
{
    list_t *new_node = malloc(sizeof(list_t));

    new_node->line = malloc(sizeof(char) * my_strlen(line));
    new_node->line = line;
    new_node->next = NULL;
    return new_node;
}
