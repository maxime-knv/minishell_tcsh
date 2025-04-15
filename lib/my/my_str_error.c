/*
** EPITECH PROJECT, 2024
** my_str_error.c
** File description:
** my str error
*/

#include "my.h"
#include <unistd.h>

int my_str_error(char *str)
{
    int len = my_strlen(str);

    write(2, str, len);
    return len;
}
