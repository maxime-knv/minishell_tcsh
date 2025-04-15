/*
** EPITECH PROJECT, 2024
** my_compute_square_root
** File description:
** return the square root of nb or 0 if not an int or exist
*/

int my_sqrt(int nb)
{
    if (nb == 1) {
        return 1;
    }
    for (int i = 0; i < nb; i++){
        if (i * i == nb) {
            return i;
        }
    }
    return 0;
}
