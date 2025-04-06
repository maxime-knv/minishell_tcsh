/*
** EPITECH PROJECT, 2024
** minishel2
** File description:
** two_right_func.c
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

int two_right_func(tree_t *tree, char **env, list_t **list)
{
    int fd = 0;
    pid_t pid = 0;
    char **arr = parse_arr(tree->right->data, " \t", 0);

    if (my_arrlen(arr) != 1 || get_sep(tree->right->data) == TWO_RIGHT) {
        write(2, "Missing name for redirect.\n", 27);
        return ERROR;
    }
    fd = open(tree->right->data, O_WRONLY | O_CREAT | O_APPEND, 0664);
    pid = fork();
    if (pid == 0) {
        dup2(fd, STDOUT_FILENO);
        recursive_exec_tree(tree->left, env, list);
        exit(0);
    }
    waitpid(-1, 0, 0);
    return SUCCESS;
}
