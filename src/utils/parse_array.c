/*
** EPITECH PROJECT, 2024
** minishel2
** File description:
** parse_array.c
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

int is_delim(char *line, int i)
{
    if ((i > 0) || (line[i] != '\0') || line[i + 1] != '\0') {
        if (line[i] == '|' || line[i] == ';')
            return 1;
        if ((line[i] == '<' && line[i + 1] == '<') ||
            (line[i] == '>' && line[i + 1] == '>')) {
            return 2;
        }
        if (line[i] == '>' || line[i] == '<')
            return 1;
    }
    return 0;
}

static char *create_new_str(char *last, char *new_str, int index)
{
    for (int i = 0; last[i] != '\0'; i++) {
        if (is_delim(last, i) == 1) {
            new_str[index] = ' ';
            new_str[index + 1] = last[i];
            new_str[index + 2] = ' ';
            index += 2;
        }
        if (is_delim(last, i) == 2) {
            new_str[index] = ' ';
            new_str[index + 1] = last[i];
            new_str[index + 2] = last[i + 1];
            new_str[index + 3] = ' ';
            index += 3;
            i += 1;
        }
        if (is_delim(last, i) == 0)
            new_str[index] = last[i];
        index += 1;
    }
    return new_str;
}

int count_nb_spaces(char *line)
{
    int delim = 0;
    int nb = 0;

    for (int i = 0; line[i] != '\0'; i++) {
        delim = is_delim(line, i);
        if (delim == 1)
            nb += 2;
        if (delim == 2) {
            nb += 2;
            i++;
        }
    }
    return nb;
}

char *preparse_line(char *line)
{
    int len = my_strlen(line);
    int nb_spaces = count_nb_spaces(line);
    char *new_str = NULL;
    int i = 0;

    new_str = malloc(sizeof(char) * (len + nb_spaces + 1));
    if (new_str == NULL)
        return NULL;
    new_str[len + nb_spaces] = '\0';
    return create_new_str(line, new_str, i);
}

static char **finish(char *new_str, char **new, int index)
{
    new[index] = my_strdup(new_str);
    free(new_str);
    index += 1;
    new[index] = NULL;
    return new;
}

char **parse_array(char *line)
{
    char **parsed_arr = parse_arr(preparse_line(line), " \t\n", 0);
    char *new_str = NULL;
    char **new = malloc(sizeof(char *) * (my_arrlen(parsed_arr) + 2));
    int j = 0;
    int index = 0;
    int i;

    for (i = 0; parsed_arr[i] != NULL; i++) {
        if (get_sep(parsed_arr[i]) != NONE &&
            my_strcmp(parsed_arr[i], "\"\"") != 0) {
            new_str = get_new_str_from_arr(parsed_arr, j, i);
            new[index] = my_strdup(new_str);
            index += 1;
            new[index] = my_strdup(parsed_arr[i]);
            index += 1;
            j = i;
        }
    }
    new_str = get_new_str_from_arr(parsed_arr, j, i);
    return finish(new_str, new, index);
}
