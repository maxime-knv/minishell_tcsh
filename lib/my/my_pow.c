/*
** EPITECH PROJECT, 2024
** my_compute_power_rev
** File description:
** return the power p of nb
*/

int my_pow(int nb, int p)
{
    int base_nb = nb;

    if (p == 0){
        return 1;
    }
    if (p < 0){
        return 0;
    }
    for (int i = 1; i < p; i++){
        nb *= base_nb;
    }
    return nb;
}
