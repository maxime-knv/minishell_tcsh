/*
** EPITECH PROJECT, 2024
** my_compute_power_rec
** File description:
** rec function to do power
*/

int my_compute_power_rec(int nb, int p)
{
    long result;

    if (p == 0) {
        return 1;
    }
    if (p < 0) {
        return 0;
    }
    result = (long)my_compute_power_rec(nb, p - 1) * nb;
    if (result > 2147483647) {
        return 0;
    }
    return (int)result;
}
