/*
** EPITECH PROJECT, 2024
** minishel1
** File description:
** execute_command.c
*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>
#include <elf.h>
#include "../include/my.h"
#include "../include/src.h"
#include "my_struct.h"

int return_value(int ret)
{
    char *mess = NULL;
    int sig = WTERMSIG(ret);

    if (sig != 0) {
        if (sig == SIGFPE)
            mini_printf("Floating exception");
        mess = strsignal(sig);
        mini_printf("%s", mess);
        if (WCOREDUMP(sig) == 0)
            mini_printf(" (core dumped)");
        mini_printf("\n");
        return ret;
    }
    return WEXITSTATUS(ret);
}

int check_magic(char *path)
{
    Elf64_Ehdr header = {0};
    int fd = open(path, O_RDONLY);

    if (read(fd, &header, sizeof(header)) != sizeof(header)) {
        return 0;
    }
    if (header.e_ident[EI_MAG0] != ELFMAG0 ||
        header.e_ident[EI_MAG1] != ELFMAG1 ||
        header.e_ident[EI_MAG2] != ELFMAG2 ||
        header.e_ident[EI_MAG3] != ELFMAG3) {
        write(2, path, my_strlen(path));
        write(2, ": Exec format error. Binary file not executable.\n", 49);
        return ERROR;
    }
    return SUCCESS;
}

int execute_command(char **parsed_line, char *path, char **env)
{
    int ret = 0;
    int fpid = 0;

    if (path == NULL)
        return ERROR;
    if (check_magic(path) == ERROR)
        return 1;
    fpid = fork();
    if (fpid == 0) {
        if (execve(path, parsed_line, env) == -1) {
            mini_printf("%s: Command not found.\n", parsed_line[0]);
            exit(1);
        }
    } else if (fpid < 0) {
        exit(1);
    }
    waitpid(fpid, &ret, 0);
    return return_value(ret);
}
