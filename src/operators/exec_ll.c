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
#include <stdio.h>
#include "mysh.h"
#include "my.h"

static int error_ll(linked_list_t **env, int fds[2])
{
    if (env == NULL)
        return EXIT_FAILURE;
    if (pipe(fds) == -1)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

static void get_input_ll(char *break_string)
{
    char *line = NULL;
    char *tmp = NULL;
    size_t n = 0;
    char *total = my_strdup("");

    if (total == NULL)
        return;
    while (getline(&line, &n, stdin) != EOF) {
        line[my_strlen(line) - 1] = '\0';
        if (my_strcmp(line, break_string) == 0)
            break;
        line[my_strlen(line)] = '\n';
        tmp = total;
        total = my_strcat_inf(2, tmp, line);
        free(tmp);
        if (total == NULL)
            break;
    }
    free(line);
    mini_printf("%s", total);
}

int exec_ll(tree_t *tree, linked_list_t **env)
{
    pid_t pid = 0;
    int fds[2] = {0};

    if (error_ll(env, fds) == EXIT_FAILURE)
        return EXIT_FAILURE;
    pid = fork();
    if (pid == -1)
        return EXIT_FAILURE;
    if (pid == 0) {
        dup2(fds[1], STDOUT_FILENO);
        close(fds[1]);
        get_input_ll(tree->right->command[0]);
        exit(0);
    }
    waitpid(pid, NULL, 0);
    dup2(fds[0], STDIN_FILENO);
    close(fds[0]);
    close(fds[1]);
    return exec_operator(tree->left, env);
}
