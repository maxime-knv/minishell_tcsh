/*
** EPITECH PROJECT, 2024
** zzz
** File description:
** zzz
*/

#ifndef MY
    #define MY
    #define DEFAULTMODE 0
    #define KEEPMODE 1

int my_arrlen(char **arr);
char *my_cut_last_char(char *test, char c);
int mini_printf(const char *format, ...);
int my_compute_square_root(int);
int my_compute_power_rec(int nb, int p);
int my_compute_power_rec(int nb, int p);
int my_find_prime_sup(int nb);
int my_getnbr(char const *str);
int my_is_prime(int nb);
void my_isneg(int n);
int my_put_nbr(int nb);
void my_putchar(char c);
int my_putstr(char const *str);
char *my_revstr(char *str);
int my_showmem(char const *str, int size);
int my_showstr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
char *my_strcapitalize(char *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char const *src);
int my_strlen(char const *str);
char *my_strlowcase(char *str);
int my_strlen(char const *str);;
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strstr(char *str, char const *to_find);
char *my_strupcase(char *str);
void my_swap(int *a, int *b);
char **my_str_to_word_array(char const *str, char c);
char *my_getenv(char *name, char **env);
int my_is_in(char *line, char *pattern);
void free_all(char **array);
char *my_strndup(const char *str, int n);
char **parse_arr(char const *str, char const *delims, int mode);


#endif /* MY */
