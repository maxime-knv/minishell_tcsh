/*
** EPITECH PROJECT, 2024
** minishel1
** File description:
** my_is_in.c
*/
/* return if a patern is in a the line */
int my_is_in(char *line, char *pattern)
{
    int new_pos = 0;

    for (int i = 0; line[i] != '\0' && pattern[new_pos] != '\0'; i++) {
        if (line[i] == pattern[new_pos]) {
            new_pos += 1;
        } else {
            new_pos = 0;
        }
        if (pattern[new_pos] == '\0') {
            return 0;
        }
    }
    return 1;
}
