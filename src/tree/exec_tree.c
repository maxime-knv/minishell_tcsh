/*
** EPITECH PROJECT, 2024
** minishel2
** File description:
** exec_tree.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdbool.h>
#include "my.h"
#include "src.h"
#include "my_struct.h"

int exec_tree(tree_t *tree, char **env, list_t **list)
{
    int saved_stdin = dup(STDIN_FILENO);
    int saved_stdout = dup(STDOUT_FILENO);
    int ret = 0;

    if (tree == NULL)
        return ERROR;
    ret = recursive_exec_tree(tree, env, list);
    free_tree(tree);
    dup2(saved_stdin, STDIN_FILENO);
    dup2(saved_stdout, STDOUT_FILENO);
    return ret;
}
