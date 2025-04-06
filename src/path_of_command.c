/*
** EPITECH PROJECT, 2024
** minishel1
** File description:
** path_of_command.c
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

char *path_of_command(char *command, char *bin_dir, int is_my)
{
    char *path = NULL;

    if (is_my == 0) {
        path = malloc(sizeof(char) *
        (my_strlen(command) + my_strlen(bin_dir) + 2));
        path = my_strcpy(path, bin_dir);
        path = my_strcat(path, "/");
        path = my_strcat(path, command);
    } else if (is_my == 1) {
        path = malloc(sizeof(char) * my_strlen(command) + sizeof(char) * 3);
        path = my_strcpy(path, "./");
        path = my_strcat(path, command);
    }
    return path;
}
