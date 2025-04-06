/*
** EPITECH PROJECT, 2024
** minishel2
** File description:
** exec_func_tree.c
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

int exec_func_tree(tree_t *tree, char **env, list_t **list)
{
    int ret = 0;
    char **arr = NULL;
    char *path = NULL;
    char **tmpenv = NULL;

    arr = parse_arr(tree->data, " \t", 0);
    if (arr == NULL)
        return SUCCESS;
    if (get_buid(arr[0]) == OTHER) {
        path = search_in_dir(arr[0], env);
        tmpenv = list_to_arr(*list);
        if (path == NULL)
            ret = execute_command(arr, arr[0], tmpenv);
        else
            ret = execute_command(arr, path, tmpenv);
    } else
        ret = exec_build_in(tree->data, list);
    return ret;
}
