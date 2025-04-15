/*
** EPITECH PROJECT, 2024
** mini_printf
** File description:
** presque printf
*/

#include <unistd.h>
#include <stdarg.h>
#include "my.h"

static void get_flag(char c, va_list args, int *count)
{
    int tmp = 0;

    if (c == 'd' || c == 'i') {
        tmp = va_arg(args, int);
        *count += my_intlen(tmp);
        my_put_nbr(tmp);
    }
    if (c == 's') {
        *count += my_putstr(va_arg(args, char *));
    }
    if (c == 'c') {
        (*count)++;
        my_putchar(va_arg(args, int));
    }
    if (c == '%') {
        my_putchar('%');
        (*count)++;
    }
}

int mini_printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%' && format[i + 1] != 'd' && format[i + 1] != 'i'
        && format[i + 1] != 's' && format[i + 1] != 'c'
        && format[i + 1] != '%')
            return EPI_ERROR;
        if (format[i] == '%') {
            get_flag(format[i + 1], args, &count);
            i++;
            continue;
        }
        count++;
        my_putchar(format[i]);
    }
    va_end(args);
    return count;
}
