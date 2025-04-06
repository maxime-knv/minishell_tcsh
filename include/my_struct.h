/*
** EPITECH PROJECT, 2024
** my_struct.h
** File description:
** struct for this project
*/

#ifndef MY_STRUCT
    #define MY_STRUCT
    #define ERROR 84
    #define SUCCESS 0
    #define H_FLAG -67
    #define ERROR_EXEC -1
    #define ID_ROOT 0
    #define SIZEOF_PASSWD 256
    #define ZERO 0
    #define FILE_ERROR -1
    #define ERROR_STRTOL -9786544
    #define SEP_LEN 7
    #define BUILD_LEN 6
    #define GROUP "/etc/group"
    #include <stdlib.h>
    #include <stdbool.h>

bool is_one_left(char const *str);
bool is_one_right(char const *str);
bool is_pipe(char const *str);
bool is_semilicon(char const *str);
bool is_two_left(char const *str);
bool is_two_right(char const *str);
bool is_cd(char const *line);
bool is_setenv(char const *line);
bool is_unsetenv(char const *line);
bool is_env(char const *line);
bool is_exit(char const *line);
typedef struct comp_s {
    char *func;
    int(*elem)(char **, char **);
} comp_t;

typedef struct list_s {
    char *line;
    struct list_s *next;
} list_t;

typedef enum {
    SEMILICON,
    ONE_LEFT,
    TWO_LEFT,
    ONE_RIGHT,
    TWO_RIGHT,
    PIPE,
    NONE,
} separator_t;

typedef struct tree_s {
    char *data;
    struct tree_s *left;
    struct tree_s *right;
} tree_t;

int semilicon_func(tree_t *tree, char **env, list_t **list);
int one_left_func(tree_t *tree, char **env, list_t **list);
int two_left_func(tree_t *tree, char **env, list_t **list);
int one_right_func(tree_t *tree, char **env, list_t **list);
int two_right_func(tree_t *tree, char **env, list_t **list);
int pipe_func(tree_t *tree, char **env, list_t **list);

static bool (*const sep_func_list[SEP_LEN])(char const *) = {
    is_semilicon,
    is_one_left,
    is_two_left,
    is_one_right,
    is_two_right,
    is_pipe,
    NULL,
};

static int (*const exec_func_list[SEP_LEN])(tree_t *, char **, list_t **) = {
    semilicon_func,
    one_left_func,
    two_left_func,
    one_right_func,
    two_right_func,
    pipe_func,
    NULL,
};

typedef enum {
    CD,
    SETENV,
    UNSETENV,
    ENV,
    EXIT,
    OTHER,
} build_in_t;

static bool (*const build_in_list[BUILD_LEN])(char const *) = {
    is_cd,
    is_setenv,
    is_unsetenv,
    is_env,
    is_exit,
    NULL,
};



typedef struct priority_sep_s {
    separator_t sep;
    char *name;
    int priority;
} priority_sep_t;

static const priority_sep_t sep_list[] = {
    {SEMILICON, ";", 5},
    {ONE_LEFT, "<", 4},
    {TWO_LEFT, "<<", 3},
    {ONE_RIGHT, ">", 2},
    {TWO_RIGHT, ">>", 2},
    {PIPE, "|", 1},
    {0}
};

#endif
