/*
** EPITECH PROJECT, 2024
** my_putchar_error.c
** File description:
**  my putchar error
*/

#include <unistd.h>

void my_putchar_error(char c)
{
    write(2, &c, 1);
}
