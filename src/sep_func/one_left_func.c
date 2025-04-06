/*
** EPITECH PROJECT, 2024
** minishel2
** File description:
** one_left_func.c
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

int one_left_func(tree_t *tree, char **env, list_t **list)
{
    int fd = 0;

    if (tree == NULL || tree->right == NULL)
        return 0;
    fd = open(tree->right->data, O_RDONLY);
    if (fd < 0) {
        write(2, tree->right->data, my_strlen(tree->right->data));
        write(2, ": No such file or directory.\n", 29);
        return ERROR;
    }
    dup2(fd, STDIN_FILENO);
    close(fd);
    recursive_exec_tree(tree->left, env, list);
    return SUCCESS;
}
