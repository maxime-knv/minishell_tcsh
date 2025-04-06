/*
** EPITECH PROJECT, 2024
** minishel2
** File description:
** search_in_dir.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdbool.h>
#include "my.h"
#include "src.h"
#include "my_struct.h"

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

char *get_path(char *bin_path, char *bin)
{
    DIR *p = NULL;
    struct dirent *pdir;

    p = opendir(bin_path);
    if (p == NULL)
        return 0;
    for (;(pdir = readdir(p)) != NULL;) {
        if (my_strcmp(pdir->d_name, bin) == 0) {
            return path_of_command(bin, bin_path, 0);
        }
    }
    return 0;
}

char *search_in_dir(char *bin, char **env)
{
    char *path = NULL;
    char **bin_paths = search_env_bin_paths(env);

    for (int i = 0; bin_paths[i] != NULL; i++) {
        path = get_path(bin_paths[i], bin);
        if (path == NULL)
            continue;
        else
            return path;
    }
    free(bin_paths);
    return NULL;
}
