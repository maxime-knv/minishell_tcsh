/*
** EPITECH PROJECT, 2025
** B-PSU-200-PAR-2-1-minishell2-ariel.amriou
** File description:
** formatsh.h
*/

#ifndef FORMATSH_H_
    #define FORMATSH_H_

     #define __maybe_unused  __attribute__((unused))

static const char *super_list[] __maybe_unused = {
    ">>",
    "<<",
    "<",
    ">",
    ";",
    "|"
};

typedef enum {
    COLON,
    SLASH,
    EQUAL,
    DOUBLE_QUOTE,
    SIMPLE_QUOTE,
    WAVE,
    DASH,
} management_t;

static const char *str_management[] __maybe_unused = {
    [COLON] = ":",
    [SLASH] = "/",
    [EQUAL] = "=",
    [DOUBLE_QUOTE] = "\"",
    [SIMPLE_QUOTE] = "\'",
    [WAVE] = "~",
    [DASH] = "-"
};

typedef enum {
    EXIT,
    UKN_USER,
    NOT_DIR,
    PERM_DENIED,
    CD_TOO_MANY,
    NO_FILE_DIR,
    SETENV_LETTER,
    SETENV_ALNUM,
    SETENV_TOO_MANY,
    UNSETENV_TOO_FEW,
    EXT_SYN,
    COM_NOT_FOUND,
    FORM_ERROR,
    FLOAT_EXP,
    CORE_DUMP,
    AMBI_IN,
    AMBI_OUT,
    MISS_NAME,
    NULL_COM,
} message_t;

static const char *str_message[] __maybe_unused = {
    [EXIT] = "exit\n",
    [UKN_USER] = "Unknown user: %s.\n",
    [NOT_DIR] = "%s: Not a directory.\n",
    [PERM_DENIED] = "%s: Permission denied.\n",
    [CD_TOO_MANY] = "cd: Too many arguments.\n",
    [NO_FILE_DIR] = "%s: No such file or directory.\n",
    [SETENV_LETTER] = "setenv: Variable name must begin with a letter.\n",
    [SETENV_ALNUM] = "setenv: Variable name must "
    "contain alphanumeric characters.\n",
    [SETENV_TOO_MANY] = "setenv: Too many arguments.\n",
    [UNSETENV_TOO_FEW] = "unsetenv: Too few arguments.\n",
    [EXT_SYN] = "exit: Expression Syntax.\n",
    [COM_NOT_FOUND] = "%s: Command not found.\n",
    [FORM_ERROR] = "%s: Exec format error. "
    "Binary file not executable.\n",
    [FLOAT_EXP] = "Floating exception",
    [CORE_DUMP] = " (core dumped)",
    [AMBI_IN] = "Ambiguous input redirect.\n",
    [AMBI_OUT] = "Ambiguous output redirect.\n",
    [MISS_NAME] = "Missing name for redirect.",
    [NULL_COM] = "Invalid null command.",
};

typedef enum {
    HOME_PATH,
    HISTORY_PATH,
    CONTENT_BASE_PATH,
    HOSTNAME,
    PASSWD,
    USER_VAR,
    HOME_VAR,
    PATH_VAR,
    OLDPWD_VAR,
    PWD_VAR,
} str_env_t;

static const char *str_env[] __maybe_unused = {
    [HOME_PATH] = "/home/",
    [HISTORY_PATH] = "/.mysh_history",
    [CONTENT_BASE_PATH] = "/bin:/usr/bin",
    [HOSTNAME] = "/etc/hostname",
    [PASSWD] = "/etc/passwd",
    [USER_VAR] = "USER",
    [HOME_VAR] = "HOME",
    [PATH_VAR] = "PATH",
    [OLDPWD_VAR] = "OLDPWD",
    [PWD_VAR] = "PWD",
};

typedef enum {
    BLUE,
    CYAN,
    YELLOW,
    RED,
    GREEN,
    MAGENTA,
    RESET,
} color_t;

static const char *str_color[] __maybe_unused = {
    [BLUE] = "\033[1;34m",
    [CYAN] = "\033[1;36m",
    [YELLOW] = "\033[1;93m",
    [RED] = "\033[1;31m",
    [GREEN] = "\033[1;32m",
    [MAGENTA] = "\033[1;35m",
    [RESET] = "\033[0m",
};

#endif
