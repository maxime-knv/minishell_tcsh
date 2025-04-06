/*
** EPITECH PROJECT, 2024
** minishel2
** File description:
** create_tree.c
*/

#include "my_struct.h"
#include "src.h"
#include "my.h"

tree_t *create_tree(char **parsed_input)
{
    int priority_index = get_priority_index(parsed_input);
    tree_t *root = create_tree_node(parsed_input[priority_index]);

    if (root == NULL)
        return root;
    root->left = create_tree(cut_array(parsed_input, 0, priority_index));
    root->right = create_tree(cut_array(parsed_input,
        priority_index + 1, my_arrlen(parsed_input)));
    return root;
}
