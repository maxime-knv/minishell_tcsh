/*
** EPITECH PROJECT, 2025
** B-PSU-200-PAR-2-1-minishell2-ariel.amriou
** File description:
** parse_cmd.c
*/

#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include "formatsh.h"
#include "mysh.h"
#include "my.h"

static void cpy_char(char *dup, char const *command, int *k, int i)
{
    dup[*k] = command[i];
    *k += 1;
}

static int jump_qote(char const delim, char const *command, int i)
{
    int j = 0;

    while (command[i + j] != '\0' && command[i + j] != delim)
        j++;
    return j;
}

static bool is_word(char const *str1, char const *str2)
{
    for (int i = 0; str2[i] != '\0'; i++)
    if (str1[i] != str2[i])
    return false;
    return true;
}

static int len_delim(char const *str, int i, int const len)
{
    for (size_t j = 0; j < ARRAY_SIZE(super_list); j++) {
        if (i + (int)j > len)
            continue;
        if (is_word(&str[i], super_list[j]) == true)
            return my_strlen(super_list[j]);
    }
    return 0;
}

static int wich_delim(char const *str, int i, int const len)
{
    for (size_t j = 0; j < ARRAY_SIZE(super_list); j++) {
        if (i + (int)j > len)
            continue;
        if (is_word(&str[i], super_list[j]) == true)
            return j;
    }
    return -1;
}

static int put_redirect(int const delim_index, char *dup, int *k)
{
    int len = 0;
    int i = 0;

    if (delim_index == -1)
        return 0;
    dup[*k] = ' ';
    *k += 1;
    len = my_strlen(super_list[delim_index]);
    for (; i < len; i++) {
        dup[*k] = super_list[delim_index][i];
        *k += 1;
    }
    dup[*k] = ' ';
    *k += 1;
    return i - 1;
}

static void fill_up_string(char const *command, int const len, char *dup)
{
    int tmp = 0;
    int k = 0;
    bool is_quote = false;

    dup[len] = '\0';
    for (int i = 0; command[i] != '\0'; i++) {
        if (command[i] == '\"' || command[i] == '\'') {
            cpy_char(dup, command, &k, i);
            is_quote = !is_quote;
            continue;
        }
        if (is_quote == true) {
            cpy_char(dup, command, &k, i);
            continue;
        }
        tmp = len_delim(command, i, len);
        i += put_redirect(wich_delim(command, i, len), dup, &k);
        if (tmp == 0)
            cpy_char(dup, command, &k, i);
    }
}

static int get_total_len(char const *command)
{
    int len = my_strlen(command);
    int tmp = 0;

    for (int i = 0; command[i] != '\0'; i++) {
        if (command[i] == '\"' || command[i] == '\'') {
            i += jump_qote(command[i], command, i + 1) + 1;
            continue;
        }
        tmp = len_delim(command, i, len);
        if (tmp != 0) {
            len += 2;
            i += tmp - 1;
        }
    }
    return len;
}

char *format_cmd(char const *command)
{
    int len = get_total_len(command);
    char *dup = NULL;

    dup = malloc((len + 1) * sizeof(char));
    if (dup == NULL)
        return NULL;
    fill_up_string(command, len, dup);
    return dup;
}
