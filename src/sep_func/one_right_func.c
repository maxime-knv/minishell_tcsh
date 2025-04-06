/*
** EPITECH PROJECT, 2024
** minishel2
** File description:
** one_right_func.c
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

static int error_handeling_right(tree_t *tree, char **arr)
{
    if (my_arrlen(arr) != 1 || get_sep(tree->right->data) == ONE_RIGHT) {
        write(2, "Missing name for redirect.\n", 27);
        return ERROR;
    }
    if (tree->left->data == NULL) {
        write(2, "Invalid null command.\n", 23);
        return ERROR;
    }
    return SUCCESS;
}

int one_right_func(tree_t *tree, char **env, list_t **list)
{
    pid_t pid = 0;
    char **arr = parse_arr(tree->right->data, " \t", 0);
    int fd = 0;

    if (error_handeling_right(tree, arr) == ERROR)
        return ERROR;
    fd = open(arr[0], O_WRONLY | O_CREAT | O_TRUNC, 0664);
    pid = fork();
    if (pid == 0) {
        dup2(fd, STDOUT_FILENO);
        close(fd);
        recursive_exec_tree(tree->left, env, list);
        exit(0);
    }
    waitpid(-1, 0, 0);
    return SUCCESS;
}
