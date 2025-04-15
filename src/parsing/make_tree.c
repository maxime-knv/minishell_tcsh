/*
** EPITECH PROJECT, 2025
** B-PSU-200-PAR-2-1-minishell2-ariel.amriou
** File description:
** make_tree.c
*/

#include <stdlib.h>
#include "mysh.h"
#include "my.h"

static void change_type(char **command,
    int i, string_redirection_t *redirection)
{
    for (int j = 0; command[j] != NULL; j++)
        if (redirection_list[i].priority > redirection->priority
            && my_strcmp(command[j], redirection_list[i].string) == 0)
            *redirection = redirection_list[i];
}

static type_t get_type(char **command)
{
    string_redirection_t redirection = {0};

    for (size_t i = 0; i < ARRAY_SIZE(redirection_list); i++)
        change_type(command, i, &redirection);
    return redirection.redirection;
}

static int is_delim(char **command, type_t redir, int index)
{
    for (int i = 0; command[i] != NULL; i++)
        if (redirection_list[index].redirection == redir &&
            my_strcmp(command[i], redirection_list[index].string) == 0)
            return i;
    return -1;
}

static int find_delim_index(char **command, type_t redir)
{
    int index = 0;

    for (size_t i = 0; i < ARRAY_SIZE(redirection_list); i++) {
        index = is_delim(command, redir, i);
        if (index != -1)
            return index;
    }
    return 0;
}

tree_t *make_tree(char **command)
{
    tree_t *head = malloc(sizeof(tree_t));
    int index = 0;

    if (head == NULL)
        return NULL;
    if (command == NULL) {
        free(head);
        return NULL;
    }
    head->command = command;
    head->left = NULL;
    head->right = NULL;
    head->redirection = get_type(head->command);
    if (head->redirection == NONE)
        return head;
    index = find_delim_index(command, head->redirection);
    head->left = make_tree(dup_list_ij(command, 0, index));
    head->right =
        make_tree(dup_list_ij(command, index + 1, my_list_len(command)));
    return head;
}
