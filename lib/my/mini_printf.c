/*
** EPITECH PROJECT, 2024
** mini_printf.c
** File description:
** meow
*/

#include <stdarg.h>
#include "my.h"

int special_cases(va_list args, const char *format, int i)
{
    if (format[i + 1] == 'd' || format[i + 1] == 'i')
        my_put_nbr(va_arg(args, int));
    if (format[i + 1] == 'c')
        my_putchar(va_arg(args, int));
    if (format[i + 1] == 's')
        my_putstr(va_arg(args, char *));
    if (format[i + 1] == '%')
        my_putchar('%');
    return 0;
}

int mini_printf(const char *format, ...)
{
    va_list args;

    va_start(args, *format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            special_cases(args, format, i);
            i += 1;
        } else
            my_putchar(format[i]);
    }
    va_end(args);
    return 0;
}
