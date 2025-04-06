/*
** EPITECH PROJECT, 2024
** my_strcpy.c
** File description:
** copies a string into another
*/

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    if (src[0] == '\0') {
        dest[i] = '\0';
    }
    while (src[i] != '\0') {
        dest[i] = src[i];
        i = i + 1;
        if (src[i] == '\0') {
            dest[i] = '\0';
        }
    }
    return dest;
}
