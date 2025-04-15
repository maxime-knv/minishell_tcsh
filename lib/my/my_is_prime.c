/*
** EPITECH PROJECT, 2024
** my_is_prime
** File description:
** return 1 if nb is a prime number, 0 if not
*/

int my_is_prime(int nb)
{
    if (nb <= 1){
        return 0;
    }
    for (int i = 2; i < nb; i++){
        if (nb % i == 0){
            return 0;
        }
    }
    return 1;
}
