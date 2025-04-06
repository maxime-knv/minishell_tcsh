/*
** EPITECH PROJECT, 2024
** minishel2
** File description:
** rec_exec_tree.c
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

int other_cases(tree_t *tree, char **env, list_t **list)
{
    int sep = get_sep(tree->data);

    exec_func_list[sep](tree, env, list);
    return sep;
}

int recursive_exec_tree(tree_t *tree, char **env, list_t **list)
{
    int ret = 0;
    int type = 0;

    if (tree == NULL)
        return 0;
    type = get_sep(tree->data);
    if (type != NONE) {
        return other_cases(tree, env, list);
    } else {
        ret = exec_func_tree(tree, env, list);
    }
    return ret;
}
