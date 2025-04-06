/*
** EPITECH PROJECT, 2024
** minishel1
** File description:
** serach_in_bin.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include "../include/my.h"
#include "../include/src.h"

int choose_bin(char *bin, char **parsed_line, char **env)
{
    char *path = path_of_command(bin, " ", 1);
    int nb = 0;

    if (parsed_line[0][0] == '/') {
        execute_command(parsed_line, parsed_line[0], env);
        return SUCCESS;
    }
    if (my_strcmp("cd", bin) == 0) {
        nb = change_directory(parsed_line, env);
    } else {
        nb = execute_command(parsed_line, path, env);
    }
    return nb;
}

char *func(char **paths, char **env)
{
    char *env_path_line = NULL;

    for (int i = 0; env[i] != NULL; i++) {
        paths = my_str_to_word_array(env[i], '=');
        if (my_strcmp(paths[0], "PATH") == 0) {
            env_path_line = paths[1];
            break;
        }
    }
    return env_path_line;
}

char **search_env_bin_paths(char **env)
{
    char **paths = NULL;
    char *env_path_line = NULL;
    char *envp[] = {
        "HOME=/",
        "PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:"
        "/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/snap/bin",
        NULL };

    if (env[0] == NULL)
        env = envp;
    env_path_line = func(paths, env);
    if (env_path_line == NULL)
        env = envp;
    env_path_line = func(paths, env);
    paths = my_str_to_word_array(env_path_line, ':');
    free(env_path_line);
    return paths;
}

int read_dir(char *bin_path, char *bin, char **parsed_line, char **env)
{
    int nb = 0;
    DIR *p = NULL;
    struct dirent *pdir;
    char *path = NULL;

    p = opendir(bin_path);
    if (p == NULL)
        return 0;
    for (;(pdir = readdir(p)) != NULL;) {
        if (my_strcmp(pdir->d_name, bin) == 0) {
            path = path_of_command(bin, bin_path, 0);
            nb = execute_command(parsed_line, path, env);
            return nb - 42;
        }
    }
    free(path);
    return 0;
}

int search_in_bin(char *bin, char **parsed_line, char **env)
{
    int nb = 0;
    char **bin_paths = search_env_bin_paths(env);

    for (int i = 0; bin_paths[i] != NULL; i++) {
        nb = read_dir(bin_paths[i], bin, parsed_line, env);
        if (nb != 0)
            return nb + 42;
    }
    free(bin_paths);
    return choose_bin(bin, parsed_line, env);
}
