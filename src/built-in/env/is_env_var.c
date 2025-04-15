/*
** EPITECH PROJECT, 2025
** B-PSU-200-PAR-2-1-minishell1-ariel.amriou
** File description:
** is_env_var.c
*/

#include "linked_list.h"
#include "my.h"
#include "formatsh.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool is_env_variable(linked_list_t **env, const char *var)
{
    linked_list_t *tmp = NULL;
    char *buff = NULL;
    char *line = NULL;

    if (env == NULL || var == NULL)
        return false;
    tmp = *env;
    while (tmp != NULL) {
        line = my_strdup(tmp->line);
        buff = strtok_r(line, str_message[EQUAL], &line);
        if (my_strcmp(buff, var) == 0) {
            free(buff);
            return true;
        }
        free(buff);
        tmp = tmp->next;
    }
    return false;
}
