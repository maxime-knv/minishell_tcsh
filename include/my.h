/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
    #define MY_H_
    #define HELP "src/help.txt"

    #define EPI_SUCCESS 0
    #define EPI_ERROR 84

void my_putchar(char c);
void my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
int my_pow(int nb, int power);
int my_sqrt(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
char **my_str_to_word_array(char const *buffer,
    char const *delim, char const *stay);
int my_str_error(char *str);
void my_putchar_error(char c);
int my_intlen(int nb);
int my_is_number(char *str);
int mini_printf(const char *format, ...);
void free_list(char **list);
int my_list_len(char **list);
char *my_strdup(char const *src);
int my_put_nbr_error(int nb);
int mini_printf_error(const char *format, ...);
char **dup_list(char **list);
char *my_strcat_inf(int count, char *str, ...);
char *my_strdup_delim(char const *path, char c);
void my_dputstr(char const fd, char const *str);
int my_free(int return_value, int fd, const char *error_message, ...);
int is_file(char *path);
char *open_file(const char *file);
int help(void);
char **dup_list_ij(char **list, int i, int j);

#endif
