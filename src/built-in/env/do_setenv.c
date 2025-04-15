/*
** EPITECH PROJECT, 2025
** B-PSU-200-PAR-2-1-minishell1-ariel.amriou
** File description:
** setenv.c
*/

#include "my.h"
#include "linked_list.h"
#include "mysh.h"
#include "formatsh.h"
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

static bool is_letter(char c, const char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (c == str[i])
            return true;
    return false;
}

static bool correct_name_var(char *var)
{
    if (var == NULL)
        return NULL;
    if (is_letter(*var, first_env_char_allowed) == false) {
        mini_printf_error(str_message[SETENV_LETTER]);
        return false;
    }
    for (int i = 0; var[i] != '\0'; i++)
        if (is_letter(var[i], env_char_allowed) == false) {
            mini_printf_error(str_message[SETENV_ALNUM]);
            return false;
        }
    return true;
}

static bool is_env_var_line(char *line, const char *var)
{
    char *line_dup = my_strdup(line);
    char *line_var = strtok_r(line_dup, str_management[EQUAL], &line_dup);

    if (line_var == NULL || my_strcmp(line_var, var) != 0) {
        free(line_var);
        return false;
    }
    free(line_var);
    return true;
}

int change_or_create(const char *var, char *value, linked_list_t **head)
{
    linked_list_t *tmp = *head;
    char *line = my_strcat_inf(
        3, (char *)var, (char *)str_management[EQUAL], value);

    if (line == NULL)
        return EPI_ERROR;
    while (tmp != NULL) {
        if (is_env_var_line(tmp->line, var) == true) {
            free(tmp->line);
            tmp->line = my_strdup(line);
            free(line);
            return EPI_SUCCESS;
        }
        tmp = tmp->next;
    }
    add_linked_list_rev(head, line);
    free(line);
    return EPI_SUCCESS;
}

int do_setenv(char **args, linked_list_t **env)
{
    int list_len = my_list_len(args);

    my_strlen(args[1]);
    if (list_len > 3) {
        mini_printf_error(str_message[SETENV_TOO_MANY]);
        return COMMAND_ERROR;
    }
    if (list_len == 1)
        return do_env(args, env);
    if (correct_name_var(args[1]) == false) {
        return COMMAND_ERROR;
    }
    if (change_or_create(args[1], args[2], env) == EPI_ERROR)
        return COMMAND_ERROR;
    return EPI_SUCCESS;
}
