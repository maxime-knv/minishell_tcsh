/*
** EPITECH PROJECT, 2025
** my_str_to_word_array.c
** File description:
** str
*/
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "my.h"

static bool check_delims(char c, char *delims)
{
    for (int i = 0; delims[i] != '\0'; i++){
        if (delims[i] == c){
            return true;
        }
    }
    return false;
}

static int count_words(char const *str, char *delims, int mode)
{
    int counter = 0;
    bool z = true;

    for (int i = 0; str[i] != '\0'; i++){
        if (check_delims(str[i], delims)
            && check_delims(str[i + 1], delims) && mode == KEEPMODE) {
            counter++;
            continue;
        }
        if (check_delims(str[i], delims) == false
            && str[i] != '\n' && z == true){
            counter++;
            z = false;
        }
        if (check_delims(str[i], delims)){
            z = true;
        }
    }
    return counter;
}

static int add_to_array(char **array_word, char *word_to_add,
    char *delims, int *i)
{
    int word_len = 0;

    for (int i = 0; word_to_add[i] != '\n'
        && check_delims(word_to_add[i], delims) == false
        && word_to_add[i] != '\0'; i++){
        word_len++;
    }
    *array_word = my_strndup(word_to_add, word_len);
    *i += word_len - 1;
    return 0;
}

static int fill_array(char **array, char *str, char *delims, int mode)
{
    int y = 0;

    for (int i = 0; str[i] != '\0'; i++){
        if (check_delims(str[i], delims)
            && check_delims(str[i + 1], delims) && mode == KEEPMODE){
            array[y] = my_strdup("\0");
            y++;
            continue;
        }
        if (check_delims(str[i], delims) == false && str[i] != '\n'){
            add_to_array(&array[y], &str[i], delims, &i);
            y++;
        }
    }
    return 0;
}

char **parse_arr(char const *str, char const *delims, int mode)
{
    char *str_dupe = my_strdup(str);
    char *delims_dupe = my_strdup(delims);
    int array_size = count_words(str_dupe, delims_dupe, mode);
    char **array = NULL;

    if (array_size == 0){
        free(str_dupe);
        return array;
    }
    array = malloc(sizeof(char *) * (array_size + 1));
    if (array == NULL)
        return NULL;
    array[array_size] = NULL;
    fill_array(array, str_dupe, delims_dupe, mode);
    free(str_dupe);
    free(delims_dupe);
    return array;
}
