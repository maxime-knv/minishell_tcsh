/*
** EPITECH PROJECT, 2024
** minishel2
** File description:
** change_env.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdbool.h>
#include "my.h"
#include "src.h"
#include "my_struct.h"

char *get_left(char *line)
{
    char *tmp = malloc(sizeof(char) * (my_strlen(line)));

    for (int i = 0; line[i] != '\0'; i++) {
        tmp[i] = line[i];
        if (line[i] == '=') {
            tmp[i] = 0;
            break;
        }
    }
    return tmp;
}

void delete_var(list_t **list, char *var)
{
    list_t *tmp = *list;
    list_t *prev = NULL;
    char *left = NULL;

    left = get_left(tmp->line);
    if (my_strcmp(left, var) == 0) {
        *list = (*list)->next;
        return;
    }
    while (tmp != NULL) {
        left = get_left(tmp->line);
        if (my_strcmp(left, var) == 0) {
            prev->next = tmp->next;
            free(tmp);
            break;
        }
        free(left);
        prev = tmp;
        tmp = tmp->next;
    }
}

static int unset_env(list_t **list, char **parsed_line)
{
    for (int i = 1; parsed_line[i] != NULL; i++)
        delete_var(list, parsed_line[i]);
    return 0;
}

static int len_arr(char **arr)
{
    int nb = 0;

    for (int i = 0; arr[i] != NULL; i++) {
        nb += 1;
    }
    return nb;
}

char **change_env(list_t **list, char *bin, char **parsed_line)
{
    char **arr = NULL;
    int len = len_arr(parsed_line);

    if (my_strcmp("setenv", bin) == 0) {
        if (setenv_error(len, parsed_line, *list) == 0)
            return SUCCESS;
        if (parsed_line[2] == NULL)
            set_env(list, parsed_line[1], "");
        else
            set_env(list, parsed_line[1], parsed_line[2]);
    }
    if (my_strcmp("unsetenv", bin) == 0) {
        if (len == 1) {
            mini_printf("unsetenv: Too few arguments.\n");
            return SUCCESS;
        }
        unset_env(list, parsed_line);
    }
    return arr;
}
