/*
** EPITECH PROJECT, 2025
** B-PSU-200-PAR-2-1-minishell2-ariel.amriou
** File description:
** check_tree.c
*/

#include <unistd.h>
#include <stdlib.h>
#include "mysh.h"
#include "my.h"
#include "formatsh.h"

int check_ll(tree_t *tree)
{
    if (tree->right != NULL && tree->right->redirection == PIPE) {
        mini_printf_error(str_message[AMBI_IN]);
        return EXIT_FAILURE;
    }
    if (error_redirect(tree->right, str_message[MISS_NAME])
        || error_redirect(tree->left, str_message[NULL_COM]))
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

int check_l(tree_t *tree)
{
    if (tree->left != NULL && tree->left->redirection == PIPE) {
        mini_printf_error(str_message[AMBI_IN]);
        return EXIT_FAILURE;
    }
    if (error_redirect(tree->right, str_message[MISS_NAME])
        || error_redirect(tree->left, str_message[NULL_COM]))
        return EXIT_FAILURE;
    if (is_file(tree->right->command[0]) == 0) {
        mini_printf_error(str_message[NO_FILE_DIR],
            tree->right->command[0]);
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int check_pipe(tree_t *tree)
{
    if (error_redirect(tree->right, str_message[NULL_COM])
        || error_redirect(tree->left, str_message[NULL_COM]))
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

int check_r_rr(tree_t *tree)
{
    if (tree->right != NULL && tree->right->redirection != NONE) {
        mini_printf_error(str_message[AMBI_OUT]);
        return EXIT_FAILURE;
    }
    if (error_redirect(tree->right, str_message[MISS_NAME])
        || error_redirect(tree->left, str_message[NULL_COM]))
        return EXIT_FAILURE;
    if (tree->right->redirection == REDIRECTION_L &&
        is_file(tree->right->right->command[0]) == 0) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

static int check_type(tree_t *tree)
{
    if (tree == NULL)
        return EXIT_SUCCESS;
    for (size_t i = 0; i < ARRAY_SIZE(type_to_func_list); i++) {
        if (type_to_func_list[i].check_error == NULL)
            continue;
        if (tree->redirection == type_to_func_list[i].redirection)
            return type_to_func_list[i].check_error(tree);
    }
    return EXIT_SUCCESS;
}

int check_tree(tree_t *tree)
{
    if (tree->left != NULL && check_tree(tree->left) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (tree->right != NULL && check_tree(tree->right) == EXIT_FAILURE)
        return EXIT_FAILURE;
    return check_type(tree);
}
