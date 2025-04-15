/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** test_42sh
*/

#include <criterion/criterion.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "formatsh.h"
#include "linked_list.h"
#include "mysh.h"
#include "my.h"

static int test_main(const char *file)
{
    char path[1024] = "tests/unitest/";
    strcat(path, file);

    int saved_stdin = dup(STDIN_FILENO);
    int input_fd = open(path, O_RDONLY);
    int result = EXIT_SUCCESS;

    if (input_fd == -1)
        return EXIT_FAILURE;
    if (dup2(input_fd, STDIN_FILENO) == -1) {
        perror("dup2 failed");
        return EXIT_FAILURE;
    }

    char PATH[1024] = "PATH=";
    strcat(PATH, getenv("PATH"));
    char HOME[1024] = "HOME=";
    strcat(HOME, getenv("HOME"));
    char *env[3] = {PATH, HOME,NULL};

    close(input_fd);
    result = mysh(list_to_linked_list(env));
    dup2(saved_stdin, STDIN_FILENO);
    close(saved_stdin);
    return result;
}

// SIMPLE CMD

Test(mysh, SUCCESS_simple_cmd)
{
    int result = test_main("SUCCESS_simple_cmd");

    cr_assert_eq(result, 0);
}

Test(mysh, ERROR_simple_cmd)
{
    int result = test_main("ERROR_simple_cmd");

    cr_assert_eq(result, 2);
}

Test(mysh, ERROR_cmd_not_exist)
{
    int result = test_main("ERROR_cmd_not_exist");

    cr_assert_eq(result, 1);
}

// SEGFAULT

Test(mysh, ERROR_floating_point)
{
    int result = test_main("ERROR_floating_point");

    cr_assert_eq(result, 136);
}

// DIRECTORY

Test(mysh, ERROR_directory)
{
    int result = test_main("ERROR_directory");

    cr_assert_eq(result, 1);
}

// SEMICOLON

Test(mysh, SUCCESS_semicolon)
{
    int result = test_main("SUCCESS_semicolon");

    cr_assert_eq(result, 0);
}

// PIPE

Test(mysh, SUCCESS_pipe)
{
    int result = test_main("SUCCESS_pipe");

    cr_assert_eq(result, 0);
}

Test(mysh, SUCCESS_pipe_builtin)
{
    int result = test_main("SUCCESS_pipe_builtin");

    cr_assert_eq(result, 0);
}

Test(mysh, ERROR_pipe_no_arg_before)
{
    int result = test_main("ERROR_pipe_no_arg_before");

    cr_assert_eq(result, 1);
}

Test(mysh, ERROR_pipe_no_arg_after)
{
    int result = test_main("ERROR_pipe_no_arg_after");

    cr_assert_eq(result, 1);
}

// CD

Test(mysh, SUCCESS_cd_simple)
{
    int result = test_main("SUCCESS_cd_simple");

    cr_assert_eq(result, 0);
}

Test(mysh, SUCCESS_cd_dir)
{
    int result = test_main("SUCCESS_cd_dir");

    cr_assert_eq(result, 0);
}

Test(mysh, ERROR_cd_not_dir)
{
    int result = test_main("ERROR_cd_not_dir");

    cr_assert_eq(result, 1);
}

Test(mysh, SUCCESS_cd_old)
{
    int result = test_main("SUCCESS_cd_old");

    cr_assert_eq(result, 0);
}

Test(mysh, SUCCESS_cd_wave)
{
    int result = test_main("SUCCESS_cd_wave");

    cr_assert_eq(result, 0);
}

Test(mysh, SUCCESS_cd_wave_user)
{
    int result = test_main("SUCCESS_cd_wave_user");

    cr_assert_eq(result, 0);
}

// EXIT

Test(mysh, SUCCESS_exit_no_arg)
{
    int result = test_main("SUCCESS_exit_no_arg");

    cr_assert_eq(result, 0);
}

Test(mysh, SUCCESS_exit_one_arg)
{
    int result = test_main("SUCCESS_exit_one_arg");

    cr_assert_eq(result, 0);
}

Test(mysh, ERROR_exit_two_arg)
{
    int result = test_main("ERROR_exit_two_arg");

    cr_assert_eq(result, 1);
}

Test(mysh, ERROR_exit_nan)
{
    int result = test_main("ERROR_exit_nan");

    cr_assert_eq(result, 1);
}

// ENV

Test(mysh, SUCCESS_env)
{
    int result = test_main("SUCCESS_env");

    cr_assert_eq(result, 0);
}

// SETENV

Test(mysh, SUCCESS_setenv_no_arg)
{
    int result = test_main("SUCCESS_setenv_no_arg");

    cr_assert_eq(result, 0);
}

Test(mysh, SUCCESS_setenv_one_arg)
{
    int result = test_main("SUCCESS_setenv_one_arg");

    cr_assert_eq(result, 0);
}

Test(mysh, SUCCESS_setenv_two_arg)
{
    int result = test_main("SUCCESS_setenv_two_arg");

    cr_assert_eq(result, 0);
}

Test(mysh, ERROR_setenv_three_arg)
{
    int result = test_main("ERROR_setenv_three_arg");

    cr_assert_eq(result, 1);
}

Test(mysh, ERROR_setenv_firts_letter)
{
    int result = test_main("ERROR_setenv_firts_letter");

    cr_assert_eq(result, 1);
}

Test(mysh, ERROR_setenv_midle_letter)
{
    int result = test_main("ERROR_setenv_midle_letter");

    cr_assert_eq(result, 1);
}

// UNSETENV

Test(mysh, SUCCESS_unsetenv)
{
    int result = test_main("SUCCESS_unsetenv");

    cr_assert_eq(result, 0);
}

Test(mysh, ERROR_unsetenv)
{
    int result = test_main("ERROR_unsetenv");

    cr_assert_eq(result, 1);
}

// REDIRECT OUT

Test(mysh, SUCCESS_redirect_simple_out)
{
    int result = test_main("SUCCESS_redirect_simple_out");

    cr_assert_eq(result, 0);
}

Test(mysh, SUCCESS_redirect_double_out)
{
    int result = test_main("SUCCESS_redirect_double_out");

    cr_assert_eq(result, 0);
}

Test(mysh, ERROR_redirect_simple_out_no_arg_before)
{
    int result = test_main("ERROR_redirect_simple_out_no_arg_before");

    cr_assert_eq(result, 1);
}

Test(mysh, ERROR_redirect_double_out_no_arg_before)
{
    int result = test_main("ERROR_redirect_double_out_no_arg_before");

    cr_assert_eq(result, 1);
}

Test(mysh, ERROR_redirect_simple_out_no_arg_after)
{
    int result = test_main("ERROR_redirect_simple_out_no_arg_after");

    cr_assert_eq(result, 1);
}

Test(mysh, ERROR_redirect_double_out_no_arg_after)
{
    int result = test_main("ERROR_redirect_double_out_no_arg_after");

    cr_assert_eq(result, 1);
}

// REDIRECT OUT

Test(mysh, SUCCESS_redirect_simple_in)
{
    int result = test_main("SUCCESS_redirect_simple_in");

    cr_assert_eq(result, 0);
}

Test(mysh, SUCCESS_redirect_double_in)
{
    int result = test_main("SUCCESS_redirect_double_in");

    cr_assert_eq(result, 1);
}

Test(mysh, ERROR_redirect_simple_in_no_arg_before)
{
    int result = test_main("ERROR_redirect_simple_in_no_arg_before");

    cr_assert_eq(result, 1);
}

Test(mysh, ERROR_redirect_double_in_no_arg_before)
{
    int result = test_main("ERROR_redirect_double_in_no_arg_before");

    cr_assert_eq(result, 1);
}

Test(mysh, ERROR_redirect_simple_in_no_arg_after)
{
    int result = test_main("ERROR_redirect_simple_in_no_arg_after");

    cr_assert_eq(result, 1);
}

Test(mysh, ERROR_redirect_double_in_no_arg_after)
{
    int result = test_main("ERROR_redirect_double_in_no_arg_after");

    cr_assert_eq(result, 1);
}

Test(mysh, ERROR_redirect_simple_in_not_exist)
{
    int result = test_main("ERROR_redirect_simple_in_not_exist");

    cr_assert_eq(result, 1);
}
