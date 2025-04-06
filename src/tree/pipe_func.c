/*
** EPITECH PROJECT, 2024
** minishel2
** File description:
** pipe_func.c
*/

#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdbool.h>
#include "src.h"
#include "my_struct.h"

int exec_first(tree_t *tree, char **env, list_t **list, int *fd)
{
    pid_t pid;

    pid = fork();
    if (pid == 0) {
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        recursive_exec_tree(tree->left, env, list);
        exit(0);
    } else if (pid < 0)
        return ERROR;
    return SUCCESS;
}

int exec_second(tree_t *tree, char **env, list_t **list, int *fd)
{
    pid_t pid;

    pid = fork();
    if (pid == 0) {
        dup2(fd[0], STDIN_FILENO);
        close(fd[1]);
        recursive_exec_tree(tree->right, env, list);
        exit(0);
    } else if (pid < 0)
        return ERROR;
    return SUCCESS;
}

void close_streams(int *fd)
{
    close(fd[0]);
    close(fd[1]);
    waitpid(-1, 0, 0);
    waitpid(-1, 0, 0);
}

int pipe_func(tree_t *tree, char **env, list_t **list)
{
    int fd[2];

    if (tree->left == NULL || tree->right == NULL) {
        write(2, "Invalid null command.\n", 22);
        return 1;
    }
    pipe(fd);
    exec_first(tree, env, list, fd);
    exec_second(tree, env, list, fd);
    close_streams(fd);
    return SUCCESS;
}
