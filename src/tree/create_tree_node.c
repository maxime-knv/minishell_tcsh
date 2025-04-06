/*
** EPITECH PROJECT, 2024
** minishel2
** File description:
** create_tree_node.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdbool.h>
#include "../include/my.h"
#include "../include/my_struct.h"

tree_t *create_tree_node(char const *data)
{
    tree_t *node = malloc(sizeof(tree_t));

    if (data == NULL)
        return NULL;
    node->data = my_strndup(data, my_strlen(data));
    node->left = NULL;
    node->right = NULL;
    return node;
}
