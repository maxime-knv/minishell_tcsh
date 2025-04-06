/*
** EPITECH PROJECT, 2024
** minishel2
** File description:
** semilicon_func.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdbool.h>
#include "my.h"
#include "src.h"
#include "my_struct.h"

int semilicon_func(tree_t *tree, char **env, list_t **list)
{
    if (tree->left == NULL) {
        recursive_exec_tree(tree->right, env, list);
        return 0;
    }
    recursive_exec_tree(tree->left, env, list);
    recursive_exec_tree(tree->right, env, list);
    return SUCCESS;
}
