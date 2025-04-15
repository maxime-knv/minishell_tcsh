/*
** EPITECH PROJECT, 2024
** mysh.h
** File description:
** mysh.h
*/

#ifndef LINKED_LIST_H_
    #define LINKED_LIST_H_

typedef struct linked_list_s {
    char *line;
    struct linked_list_s *next;
} linked_list_t;

int add_linked_list(linked_list_t **head, char *line);
int add_linked_list_rev(linked_list_t **head, char *line);
int del_linked_list(linked_list_t **head, char *var);
int disp_linked_list(linked_list_t **head);
linked_list_t **list_to_linked_list(char **env);
int linked_list_len(linked_list_t **head);
char **linked_list_to_list(linked_list_t **head);
void delete_linked_list(linked_list_t **head);

#endif
