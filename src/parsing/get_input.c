/*
** EPITECH PROJECT, 2025
** B-PSU-200-PAR-2-1-minishell1-ariel.amriou
** File description:
** get_input.c
*/

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include "my.h"
#include "mysh.h"
#include "formatsh.h"

static void write_history(char *command, char *user)
{
    char *path = my_strcat_inf(3, (char *)str_env[HOME_PATH],
        user, str_env[HISTORY_PATH]);
    int fd = 0;

    if (path == NULL)
        return;
    fd = open(path, O_RDWR | O_APPEND);
    free(path);
    if (fd == -1)
        return;
    write(fd, command, my_strlen(command));
}

static void write_path(char *home)
{
    char *wd = getcwd(NULL, PATH_MAX_LEN);
    int len = 0;

    if (home != NULL) {
        len = strlen(home);
        if (strncmp(home, wd, len) == 0)
            wd += len;
        else
            len = 0;
        free(home);
    }
    mini_printf("%s~%s>", str_color[MAGENTA], wd);
    if (len != 0)
        wd -= len;
    free(wd);
}

static void prompt(prompt_t *variables, char *home)
{
    write_path(home);
    if (variables->hostname != NULL)
        mini_printf("%s ✭ %s%s", str_color[BLUE],
            str_color[YELLOW], variables->hostname);
    if (variables->status == 0)
        mini_printf("%s\n%d", str_color[GREEN], variables->status);
    else
        mini_printf("%s\n%d", str_color[RED], variables->status);
    if (variables->user == NULL)
        variables->user = my_strdup("$ ");
    mini_printf("%s - %s%s➤ %s", str_color[RESET], str_color[CYAN],
        variables->user, str_color[RESET]);
}

int get_input(
    char **command, char ***args, prompt_t *variables, linked_list_t **env)
{
    char *tmp = NULL;
    size_t size = 0;

    if (isatty(STANDARD_INPUT) == 1)
        prompt(variables, get_env_var(env, str_env[HOME_VAR]));
    if (getline(command, &size, stdin) == EOF)
        return EPI_ERROR;
    write_history(*command, variables->user);
    tmp = format_cmd(*command);
    if (tmp == NULL)
        return EPI_ERROR;
    *args = my_str_to_word_array(tmp, " \n\t", "\"\'");
    free(tmp);
    if (*args == NULL)
        return EPI_ERROR;
    if (replace_wave(*args, env) == COMMAND_ERROR) {
        variables->status = COMMAND_ERROR;
        return COMMAND_ERROR;
    }
    return EPI_SUCCESS;
}
