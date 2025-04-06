/*
** EPITECH PROJECT, 2024
** minishel1
** File description:
** change_directory.c
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include "../include/my.h"
#include "../include/src.h"

static int handle_error(char *dir)
{
    struct stat dir_stat;

    if (dir == NULL)
        return SUCCESS;
    if (stat(dir, &dir_stat) == 0) {
        if (!S_ISDIR(dir_stat.st_mode)) {
            mini_printf("%s: Not a directory.\n", dir);
            return ERROR;
        }
    } else if (dir[0] != '~' && dir[0] != '-'){
        mini_printf("%s: No such file or directory.\n", dir);
        return ERROR;
    }
    if (access(dir, R_OK && X_OK) == -1
    && dir[0] != '~' && dir[0] != '-') {
        mini_printf("%s: Permission denied.\n", dir);
        return ERROR;
    }
    return SUCCESS;
}

int exec_cd(char **path, char *home_path, char *old_pwd)
{
    char prev[512];
    size_t s = 512;

    getcwd(prev, s);
    if (path[1] == NULL || my_strcmp(path[1], " ") == 0 ||
    my_strcmp(path[1], "~") == 0) {
        chdir(home_path);
        return 0;
    }
    if (my_strcmp(path[1], "-") == 0)
        chdir(old_pwd);
    else {
        if (chdir(path[1]) == -1) {
            return ERROR;
        }
    }
    return SUCCESS;
}

int change_directory(char **path, char **env)
{
    char *home_path = "";
    char *old_pwd = "";

    if (env != NULL) {
        home_path = my_getenv("HOME", env);
        old_pwd = my_getenv("OLDPWD", env);
    }
    if (handle_error(path[1]) == ERROR)
        return ERROR;
    return exec_cd(path, home_path, old_pwd);
}
