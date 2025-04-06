/*
** EPITECH PROJECT, 2024
** minishel2
** File description:
** exec_buid_in.c
*/

#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdbool.h>
#include "my.h"
#include "src.h"
#include "my_struct.h"

int env_func(list_t **list)
{
    print_list(*list);
    return SUCCESS;
}

int exec_build_in(char *command, list_t **list)
{
    char **parsed_command = my_str_to_word_array(command, ' ');
    int build_int = get_buid(parsed_command[0]);
    char **tmpenv = list_to_arr(*list);

    if (build_int == CD)
        change_directory(parsed_command, tmpenv);
    if (build_int == SETENV || build_int == UNSETENV)
        change_env(list, parsed_command[0], parsed_command);
    if (build_int == ENV)
        env_func(list);
    return 0;
}
