/*
** EPITECH PROJECT, 2024
** my_putstr
** File description:
** print the string
*/

#include "my.h"
#include <unistd.h>

void my_dputstr(char const fd, char const *str)
{
    write(fd, str, my_strlen(str));
}
