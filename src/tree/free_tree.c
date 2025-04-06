/*
** EPITECH PROJECT, 2024
** minishel2
** File description:
** free_tree.c
*/

#include <stdlib.h>
#include "my_struct.h"

void free_tree(tree_t *tree)
{
    if (tree == NULL)
        return;
    else {
        free_tree(tree->left);
        free_tree(tree->right);
        free(tree);
    }
}
