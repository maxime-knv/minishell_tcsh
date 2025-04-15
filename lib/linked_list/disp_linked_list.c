/*
** EPITECH PROJECT, 2024
** B-CPE-110-PAR-1-1-organized-ariel.amriou
** File description:
** disp.c
*/

#include <stdlib.h>
#include <unistd.h>
#include "linked_list.h"
#include "my.h"

int disp_linked_list(linked_list_t **head)
{
    linked_list_t *tmp = NULL;

    if (head == NULL)
        return 84;
    tmp = *head;
    while (tmp != NULL) {
        if (tmp != NULL && my_strcmp(tmp->line, "") != 0)
            mini_printf("%s\n", tmp->line);
        tmp = tmp->next;
    }
    return 0;
}
