/*
** EPITECH PROJECT, 2024
** minishel1
** File description:
** print_list.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "../../include/src.h"
#include "../../include/my.h"
#include "../../include/src.h"

int print_list(list_t *head)
{
    list_t *tmp = head;

    if (tmp == NULL)
        return 0;
    while (tmp != NULL) {
        mini_printf("%s\n", tmp->line);
        tmp = tmp->next;
    }
    return SUCSESS;
}
