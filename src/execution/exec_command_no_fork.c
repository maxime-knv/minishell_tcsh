/*
** EPITECH PROJECT, 2025
** B-PSU-200-PAR-2-1-minishell2-ariel.amriou
** File description:
** exec_command_no_fork.c
*/

#include <stdlib.h>
#include "mysh.h"
#include "my.h"

void exec_command_no_fork(char **args, linked_list_t **env,
    char **path, char **env_list)
{
    for (size_t i = 0; i < ARRAY_SIZE(commands); i++)
        if (my_strcmp(commands[i].command, args[0]) == 0) {
            commands[i].exec(args, env);
            exit(0);
        }
    command(args, env, path, env_list);
}
