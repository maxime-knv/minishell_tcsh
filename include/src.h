/*
** EPITECH PROJECT, 2024
** zzz
** File description:
** zzz
*/

#ifndef SRC_H
    #define SRC_H
    #include "my_struct.h"
    #include <sys/types.h>
    #define SUCSESS 0
    #define ERROR 84
    #define SEXFAULT 139

int setenv_error(int len, char **parsed_line, list_t *list);
int my_char_not_in(char const *str, char c);
int get_user_input(char **env, list_t **list);
int execute(char *line, char **env, list_t **list);
int error_handeling(int ac, char **av);
int change_directory(char **path, char **env);
int search_in_bin(char *bin, char **parsed_line, char **env);
int execute_command(char **parsed_line, char *path, char **env);
char *path_of_command(char *command, char *bin_dir, int is_my);
int my_setenv(list_t **list, char **env);
char *my_mulcat(int len, ...);
int add_env_to_list(list_t **head, char **env);
list_t *create_node(char *line);
list_t *create_val(char const *name, char *val);
char **list_to_arr(list_t *head);
int print_list(list_t *head);
int set_env(list_t **head, char const *name, char *val);
int len_linked_list(list_t *head);
char **list_to_arr(list_t *head);
tree_t *create_tree_node(char const *data);
tree_t *create_tree(char **parsed_input);
void print_tree(tree_t *tree);
char *get_new_str_from_arr(char **arr, int beggin, int end);
int get_sep(char *value);
int get_priority_index(char **parsed_input);
char **cut_array(char **arr, int i, int j);
int get_buid(char *value);
char **parse_array(char *line);
char **change_env(list_t **list, char *bin, char **parsed_line);
int exec_tree(tree_t *tree, char **env, list_t **list);
int exec_build_in(char *command, list_t **list);
char *search_in_dir(char *bin, char **env);
int exec_func_tree(tree_t *tree, char **env, list_t **list);
int pipe_func(tree_t *tree, char **env, list_t **list);
int recursive_exec_tree(tree_t *tree, char **env, list_t **list);
void free_tree(tree_t *tree);
int one_right_func(tree_t *tree, char **env, list_t **list);
int two_right_func(tree_t *tree, char **env, list_t **list);

#endif /* SRC_H */
