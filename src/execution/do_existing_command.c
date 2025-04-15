/*
** EPITECH PROJECT, 2024
** B-PSU-200-PAR-2-1-minishell1-ariel.amriou
** File description:
** do_ls.c
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <errno.h>
#include <stdbool.h>
#include <fcntl.h>
#include "mysh.h"
#include "my.h"
#include "formatsh.h"

int is_file_error(char *path)
{
    struct stat file_stat = {0};

    if (stat(path, &file_stat) == -1) {
        mini_printf_error(str_message[COM_NOT_FOUND], path);
        return false;
    }
    if (S_ISREG(file_stat.st_mode) == false) {
        mini_printf_error(str_message[PERM_DENIED], path);
        return false;
    }
    return true;
}

static bool is_good_archi(char const *file)
{
    int fd = open(file, O_RDONLY);
    int byte = 0;

    if (fd == -1)
        return false;
    read(fd, &byte, 4);
    if (byte != ARCHI_MAGIC)
        return false;
    read(fd, &byte, 1);
    return true;
}

static void is_correct_file(char *file)
{
    if (is_file_error(file) == false)
        exit(1);
    if (is_good_archi(file) == false) {
        mini_printf_error(str_message[FORM_ERROR], file);
        exit(1);
    }
}

static void error(int *status)
{
    int signal = WTERMSIG(*status);

    if (signal != 0) {
        if (signal == SIGFPE)
            mini_printf_error("%s", str_message[FLOAT_EXP]);
        else
            mini_printf_error("%s", strsignal(signal));
        if (__WCOREDUMP(signal) != 0)
            mini_printf_error(str_message[CORE_DUMP]);
        mini_printf_error("\n");
        return;
    }
    *status = WEXITSTATUS(*status);
}

void command(char **args, linked_list_t **env,
    char **path, char **env_list)
{
    char *error = NULL;
    char *paths = get_env_var(env, str_env[PATH_VAR]);

    if (is_env_variable(env, str_env[PATH_VAR]) == false)
        paths = my_strdup(str_env[CONTENT_BASE_PATH]);
    *path = wich_path(args[0], paths);
    if (*path == NULL)
        *path = args[0];
    is_correct_file(*path);
    if (execve(*path, args, env_list) == -1) {
        error = strerror(errno);
        mini_printf_error("%s: %s.\n", *path, error);
        exit(1);
    }
}

int do_existing_command(char **args, linked_list_t **env)
{
    int status = 0;
    char *path = NULL;
    char **env_list = linked_list_to_list(env);
    pid_t pid = fork();

    if (pid == -1 || env_list == NULL)
        return EPI_ERROR;
    if (pid == 0) {
        command(args, env, &path, env_list);
    }
    if (pid > 0) {
        waitpid(pid, &status, 0);
        close(STDOUT_FILENO);
        close(STDIN_FILENO);
        error(&status);
        free(path);
        free_list(env_list);
        path = NULL;
    }
    return status;
}
