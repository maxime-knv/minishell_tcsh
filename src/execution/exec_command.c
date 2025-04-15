/*
** EPITECH PROJECT, 2025
** B-PSU-200-PAR-2-1-minishell2-ariel.amriou
** File description:
** exec_command.c
*/

#include "mysh.h"
#include "my.h"

int exec_command(char **args, linked_list_t **env)
{
    for (size_t i = 0; i < ARRAY_SIZE(commands); i++)
        if (my_strcmp(commands[i].command, args[0]) == 0)
            return commands[i].exec(args, env);
    return do_existing_command(args, env);
}
