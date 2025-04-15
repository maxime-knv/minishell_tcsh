/*
** EPITECH PROJECT, 2025
** B-PSU-200-PAR-2-1-minishell2-ariel.amriou
** File description:
** exec_operator.c
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include "mysh.h"
#include "my.h"

int exec_operator(tree_t *tree, linked_list_t **env)
{
    if (tree->redirection == NONE)
        return exec_command(tree->command, env);
    for (size_t i = 0; i < ARRAY_SIZE(type_to_func_list); i++)
        if (tree->redirection == type_to_func_list[i].redirection)
            return type_to_func_list[i].exec_operator(tree, env);
    return EPI_ERROR;
}
