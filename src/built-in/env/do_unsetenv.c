/*
** EPITECH PROJECT, 2025
** B-PSU-200-PAR-2-1-minishell1-ariel.amriou
** File description:
** unsetenv.c
*/

#include "linked_list.h"
#include "my.h"
#include "mysh.h"
#include "formatsh.h"


int do_unsetenv(char **args, linked_list_t **env)
{
    if (args == NULL)
        return COMMAND_ERROR;
    if (my_list_len(args) < 2) {
        mini_printf_error(str_message[UNSETENV_TOO_FEW]);
        return COMMAND_ERROR;
    }
    args++;
    while (*args != NULL) {
        del_linked_list(env, *args);
        args++;
    }
    return EPI_SUCCESS;
}
