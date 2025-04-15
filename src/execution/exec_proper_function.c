/*
** EPITECH PROJECT, 2025
** B-PSU-200-PAR-2-1-minishell1-ariel.amriou
** File description:
** exec_proper_function.c
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include "mysh.h"
#include "my.h"

static int parse_tree(tree_t *tree, linked_list_t **env)
{
    int dup_stdin = 0;
    int dup_stdout = 0;
    int ret = 0;

    if (tree == NULL || tree->command == NULL || tree->command[0] == NULL)
        return EXIT_SUCCESS;
    if (tree->redirection != SEMICOLON) {
        if (check_tree(tree) == EXIT_FAILURE)
            return EXIT_FAILURE;
        dup_stdin = dup(STDIN_FILENO);
        dup_stdout = dup(STDOUT_FILENO);
        ret = exec_operator(tree, env);
        dup2(dup_stdout, STDOUT_FILENO);
        close(dup_stdout);
        dup2(dup_stdin, STDIN_FILENO);
        close(dup_stdin);
        return ret;
    }
    parse_tree(tree->left, env);
    return parse_tree(tree->right, env);
}

int exec_proper_function(char **args,
    linked_list_t **env, int return_value)
{
    tree_t *tree = NULL;

    if (args == NULL || args[0] == NULL)
        return return_value;
    tree = make_tree(args);
    if (tree == NULL)
        return EPI_ERROR;
    return parse_tree(tree, env);
}
