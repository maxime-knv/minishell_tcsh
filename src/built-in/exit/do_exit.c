/*
** EPITECH PROJECT, 2025
** B-PSU-200-PAR-2-1-minishell1-ariel.amriou
** File description:
** do_env.c
*/


#include <stdlib.h>
#include "my.h"
#include "mysh.h"
#include "linked_list.h"
#include "formatsh.h"

int do_exit(char **args, linked_list_t **env)
{
    int exit_code = 0;

    if (my_list_len(args) > 2) {
        mini_printf_error(str_message[EXT_SYN]);
        return COMMAND_ERROR;
    }
    if (args[1] != NULL) {
        if (my_is_number(args[1]) == 0) {
            mini_printf_error(str_message[EXT_SYN]);
            return COMMAND_ERROR;
        }
        exit_code = my_getnbr(args[1]);
    }
    free_list(args);
    delete_linked_list(env);
    exit(exit_code);
    return EPI_SUCCESS;
}
