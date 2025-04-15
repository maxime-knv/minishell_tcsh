/*
** EPITECH PROJECT, 2025
** B-PSU-200-PAR-2-1-minishell2-ariel.amriou
** File description:
** exec_l.c
*/

#include <fcntl.h>
#include "mysh.h"

int exec_r(tree_t *tree, linked_list_t **env)
{
    return exec_rr_r(tree, env, O_TRUNC);
}
