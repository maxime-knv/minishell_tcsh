/*
** EPITECH PROJECT, 2025
** B-PSU-200-PAR-2-1-minishell2-ariel.amriou
** File description:
** exec_rr_r.c
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include "mysh.h"
#include "my.h"

static int error_l(tree_t *tree, linked_list_t **env, int *fd)
{
    if (env == NULL)
        return EXIT_FAILURE;
    *fd = open(tree->right->command[0], O_RDONLY);
    if (*fd == -1) {
        mini_printf_error("%s: %s.\n",
            tree->right->command[0], strerror(errno));
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int exec_l(tree_t *tree, linked_list_t **env)
{
    int fd = 0;
    pid_t pid = 0;
    int status[] = {0};

    if (error_l(tree, env, &fd) == EXIT_FAILURE)
        return EXIT_FAILURE;
    dup2(fd, STDIN_FILENO);
    close(fd);
    pid = fork();
    if (pid == -1)
        return EXIT_FAILURE;
    if (pid == 0) {
        exit(status[0]);
    }
    status[0] = exec_operator(tree->left, env);
    waitpid(pid, NULL, 0);
    return status[0];
}
