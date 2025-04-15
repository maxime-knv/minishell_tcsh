/*
** EPITECH PROJECT, 2025
** B-PSU-200-PAR-2-1-minishell1-ariel.amriou
** File description:
** do_env.c
*/


#include "my.h"
#include "mysh.h"
#include "linked_list.h"

int do_env(char **args, linked_list_t **env)
{
    if (args == NULL || env == NULL)
        return ENV_ERROR;
    disp_linked_list(env);
    return EPI_SUCCESS;
}
