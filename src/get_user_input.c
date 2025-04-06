/*
** EPITECH PROJECT, 2024
** minishel1
** File description:
** get_user_input.c
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

int execute(char *line, char **env, list_t **list)
{
    int save_stdin = dup(STDIN_FILENO);
    int save_stdout = dup(STDOUT_FILENO);
    char **parsed_arr = NULL;
    tree_t *tree = NULL;
    int ret = 0;

    if (my_strcmp(line, "\n") == 0)
        return SUCCESS;
    parsed_arr = parse_array(line);
    tree = create_tree(parsed_arr);
    if (my_strcmp(tree->data, "exit") == 0)
        exit(SUCCESS);
    ret = exec_tree(tree, env, list);
    dup2(save_stdin, STDIN_FILENO);
    dup2(save_stdout, STDOUT_FILENO);
    close(save_stdin);
    close(save_stdout);
    return ret;
}

int get_user_input(char **env, list_t **list)
{
    char *buff = NULL;
    size_t len = 0;
    ssize_t read = 0;
    int ret = 0;
    int exit = 0;
    
    while (exit != 1) {
        if (isatty(0) == 1)
            mini_printf("\x1b[31m$> \x1b[0m");
        read = getline(&buff, &len, stdin);
        if (read == EOF)
            break;
        ret = execute(buff, env, list);
    }
    return ret;
}
