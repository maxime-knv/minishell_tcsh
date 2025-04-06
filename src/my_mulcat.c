/*
** EPITECH PROJECT, 2024
** minishel1
** File description:
** my_mulcat.c
*/

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "../include/src.h"
#include "../include/my.h"

static int handle_error(char *tmp)
{
    if (tmp == NULL)
        return ERROR;
    else
        return SUCCESS;
}

int get_len_of_args(va_list list, char *tmp, size_t size, int len)
{
    for (int i = 0; i < len; i++) {
    tmp = va_arg(list, char *);
    if (handle_error(tmp) == ERROR)
        return 0;
    size += sizeof(char) * (my_strlen(tmp));
    }
    return size;
}

char *my_mulcat(int len, ...)
{
    char *output = NULL;
    size_t size = 0;
    va_list list;
    char *tmp = NULL;

    va_start(list, len);
    size = get_len_of_args(list, tmp, size, len);
    va_end(list);
    output = malloc(sizeof(char) * (size + len));
    if (output == NULL)
        return NULL;
    output = my_strcpy(output, "\0");
    va_start(list, len);
    for (int i = 0; i < len; i++)
        output = my_strcat(output, va_arg(list, char *));
    va_end(list);
    return output;
}
