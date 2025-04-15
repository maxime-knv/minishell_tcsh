/*
** EPITECH PROJECT, 2025
** B-PSU-200-PAR-2-1-minishell1-ariel.amriou
** File description:
** mysh.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "mysh.h"
#include "my.h"
#include "formatsh.h"

static int change_old_pwd(linked_list_t **env)
{
    char *path = get_env_var(env, str_env[OLDPWD_VAR]);

    if (path == NULL)
        return EPI_SUCCESS;
    free(path);
    if (change_or_create(str_env[OLDPWD_VAR], NULL, env) == EPI_ERROR)
        return EPI_ERROR;
    return EPI_SUCCESS;
}

static int free_all(char *command,
    char **args, linked_list_t **env, prompt_t *variable)
{
    if (isatty(STANDARD_INPUT) == 1)
        mini_printf(str_message[EXIT]);
    free(command);
    free_list(args);
    free(variable->user);
    free(variable->hostname);
    delete_linked_list(env);
    return 0;
}

void init_prompt(prompt_t *variable, linked_list_t **env)
{
    int len = 0;

    variable->user = get_env_var(env, str_env[USER_VAR]);
    variable->hostname = open_file(str_env[HOSTNAME]);
    if (variable->hostname != NULL) {
        len = strlen(variable->hostname);
        if (variable->hostname[len - 1] == '\n')
            variable->hostname[len - 1] = '\0';
    }
    variable->status = 0;
}

int mysh(linked_list_t **env)
{
    char *command = NULL;
    char **args = NULL;
    prompt_t variables = {NULL};
    int status = EPI_SUCCESS;

    init_prompt(&variables, env);
    if (env == NULL || change_old_pwd(env) == EPI_ERROR)
        return EPI_ERROR;
    while (status != EPI_ERROR) {
        status = get_input(&command, &args, &variables, env);
        if (status == EPI_ERROR)
            break;
        if (status == COMMAND_ERROR)
            continue;
        variables.status = exec_proper_function(args, env, variables.status);
        free_list(args);
        args = NULL;
    }
    free_all(command, args, env, &variables);
    return variables.status;
}
