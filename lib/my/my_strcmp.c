/*
** EPITECH PROJECT, 2024
** my_strcmp.c
** File description:
** zzz
*/

#include "my.h"

static int check_if_bigger(char const s1, char const s2)
{
    if (s1 > s2)
        return 1;
    if (s1 < s2)
        return -1;
    return 0;
}

static int check_strings_are_equal(char const *s1, char const *s2, int i)
{
    while (s1[i] && s2[i] && s1[i + 1] != '\0' && s2[i + 1] != '\0') {
        if (s1[i] == s2[i]) {
            i += 1;
        }
        if (s1[i] != s2[i]) {
            return check_if_bigger(s1[i], s2[i]);
        } else
            i += 1;
    }
    return 0;
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    if (s1[i] == s2[i] && my_strlen(s1) == my_strlen(s2))
        return check_strings_are_equal(s1, s2, i);
    if (s1[i] != s2[i])
        return check_if_bigger(s1[i], s2[i]);
    return 84;
}
