/*
** EPITECH PROJECT, 2024
** minishel1
** File description:
** mysh.c
*/

#include "src.h"
#include "my_struct.h"

int free_list(list_t *head)
{
    list_t *tmp = head;

    if (tmp == NULL) {
        free(tmp);
        return SUCCESS;
    }
    while (tmp != NULL) {
        free(tmp->line);
        tmp = tmp->next;
    }
    return SUCSESS;
}

int main(int ac, char **av, char **env)
{
    int nb = 0;
    list_t *list = NULL;

    add_env_to_list(&list, env);
    nb = get_user_input(env, &list);
    return nb;
}
