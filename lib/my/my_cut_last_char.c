/*
** EPITECH PROJECT, 2024
** minishel1
** File description:
** my_cut_last_char.c
*/

char *my_cut_last_char(char *test, char c)
{
    int i = 0;

    while (test[i] != '\0') {
        if (test[i] == c)
            test[i] = '\0';
        i++;
    }
    return test;
}
