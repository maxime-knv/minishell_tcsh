/*
** EPITECH PROJECT, 2024
** minishel2
** File description:
** print_tree.c
*/

#include "my.h"
#include "my_struct.h"

void print_tree(tree_t *tree)
{
    if (tree == NULL)
        return;
    print_tree(tree->left);
    mini_printf("'%s'\n", tree->data);
    print_tree(tree->right);
}
