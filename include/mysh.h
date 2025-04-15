/*
** EPITECH PROJECT, 2024
** mysh.h
** File description:
** mysh.h
*/

#ifndef SRC_H_
    #define SRC_H_
    #include "linked_list.h"
    #include <stddef.h>
    #include <stdbool.h>

    /* return values */
    #define EPI_ERROR 84
    #define EPI_SUCCESS 0
    #define COMMAND_ERROR 1
    #define ENV_ERROR 125

    /* standard lenght */
    #define PATH_MAX_LEN 512

    /* architecture magic as int */
    #define ARCHI_MAGIC 1179403647
    /* other */
    #define STANDARD_INPUT 0

    #define ARRAY_SIZE(array) (unsigned int)(sizeof(array) / sizeof(*array))

typedef enum type {
    NONE,
    SEMICOLON,
    PIPE,
    REDIRECTION_L,
    REDIRECTION_LL,
    REDIRECTION_R,
    REDIRECTION_RR
} type_t;

typedef struct tree_s {
    char **command;
    type_t redirection;
    struct tree_s *left;
    struct tree_s *right;
} tree_t;

typedef struct string_redirection_s {
    type_t redirection;
    char *string;
    unsigned int priority;
} string_redirection_t;

static const string_redirection_t redirection_list[] = {
    {SEMICOLON, ";", 5},
    {REDIRECTION_R, ">", 4},
    {REDIRECTION_RR, ">>", 3},
    {REDIRECTION_L, "<", 2},
    {REDIRECTION_LL, "<<", 2},
    {PIPE, "|", 1}
};

typedef struct prompt {
    char *user;
    char *hostname;
    int status;
} prompt_t;

int exec_proper_function(char **args,
    linked_list_t **env, int return_value);
int mysh(linked_list_t **env);
int get_input(
    char **command, char ***args, prompt_t *variables, linked_list_t **env);
int change_or_create(const char *var, char *value, linked_list_t **head);
bool is_env_variable(linked_list_t **env, const char *var);
char *get_env_var(linked_list_t **env, const char *var);
char *wich_path(char *command, char *paths);
void command(char **args, linked_list_t **env,
    char **path, char **env_list);
char *format_cmd(char const *command);
int replace_wave(char **arg, linked_list_t **env);

/* built-in */
int do_existing_command(char **args, linked_list_t **env);
int do_cd(char **args, linked_list_t **env);
int do_env(char **args, linked_list_t **env);
int do_setenv(char **args, linked_list_t **env);
int do_unsetenv(char **args, linked_list_t **env);
int do_exit(char **args, linked_list_t **env);

/* operators */
int error_redirect(tree_t *branch, const char *error_msg);
int exec_rr_r(tree_t *tree, linked_list_t **env, int mode);
int exec_pipe(tree_t *tree, linked_list_t **env);
int exec_r(tree_t *tree, linked_list_t **env);
int exec_rr(tree_t *tree, linked_list_t **env);
int exec_l(tree_t *tree, linked_list_t **env);
int exec_ll(tree_t *tree, linked_list_t **env);
int check_tree(tree_t *tree);
int check_r_rr(tree_t *tree);
int check_pipe(tree_t *tree);
int check_l(tree_t *tree);
int check_ll(tree_t *tree);

/* execution */
void exec_command_no_fork(char **args, linked_list_t **env,
    char **path, char **env_list);
int exec_command(char **args, linked_list_t **env);
int exec_operator(tree_t *tree, linked_list_t **env);

typedef struct type_to_func_s {
    const type_t redirection;
    int (*exec_operator)(tree_t *tree, linked_list_t **env);
    int (*check_error)(tree_t *tree);
} type_to_func_t;

static const type_to_func_t type_to_func_list[] = {
    {PIPE, &exec_pipe, &check_pipe},
    {REDIRECTION_R, &exec_r, &check_r_rr},
    {REDIRECTION_RR, &exec_rr, &check_r_rr},
    {REDIRECTION_L, &exec_l, &check_l},
    {REDIRECTION_LL, &exec_ll, &check_ll}
};

/* binary tree */
tree_t *make_tree(char **command);

typedef struct exec_command {
    const char *command;
    int (*exec)(char **args, linked_list_t **env);
} exec_command_t;

static const exec_command_t commands[] = {
    {"cd", &do_cd},
    {"env", &do_env},
    {"setenv", &do_setenv},
    {"unsetenv", &do_unsetenv},
    {"exit", &do_exit}
};

/* letter allowed for fist env variable name */
static const char first_env_char_allowed[] =
"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz_";

/* letter allowed for env variable name */
static const char env_char_allowed[] =
"1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz_.";

#endif
