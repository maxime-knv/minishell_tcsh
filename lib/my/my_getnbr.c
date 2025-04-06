/*
** EPITECH PROJECT, 2024
** my_getnbr
** File description:
** get nbr
*/

static int modify_add(char const *str, int i, long int *add, int *negative)
{
    int number = 0;

    if (str[i] >= '0' && str[i] <= '9'){
        number = str[i] - '0';
        *add = *add * 10 + number * *negative;
        i = i + 1;
        return i;
    }
    if (str[i] == '-'){
        *negative = *negative * -1;
        i = i + 1;
    } else {
        i = i + 1;
    }
    return i;
}

int my_getnbr(char const *str)
{
    int i = 0;
    long int add = 0;
    int negative = 1;

    while (str[i] != '\0') {
        i = modify_add(str, i, &add, &negative);
        if (i == 0)
            return 0;
        if (add >= 2147483647 || add <= -2147483647){
            return 0;
        }
        if ((str[i] < '0' || str[i] > '9') && str[i]
            != '-' && str[i] != '+' && add != 0){
            return add;
        }
    }
    return add;
}
