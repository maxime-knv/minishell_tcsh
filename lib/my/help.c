/*
** EPITECH PROJECT, 2025
** B-MUL-100-PAR-1-1-myhunter-ariel.amriou
** File description:
** main.c
*/

#include "my.h"
#include <stddef.h>

int help(void)
{
    char *help = open_file(HELP);

    if (help == NULL)
        mini_printf_error("Error while opening %s file\n", HELP);
    else
        mini_printf("%s", help);
    return EPI_ERROR;
}
