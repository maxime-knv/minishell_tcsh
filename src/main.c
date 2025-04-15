/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main function
*/

#include <stdio.h>
#include "mysh.h"
#include "my.h"

int main(int const argc,
    char const __attribute_maybe_unused__ **argv, char **env)
{
    if (argc != 1)
        return 84;
    return mysh(list_to_linked_list(env));
}
