/*
** EPITECH PROJECT, 2024
** my_find_prime_sup
** File description:
** returns the smallest prime number
** that is greater than, or equal to, the
** number given as a parameter
*/

#include "my.h"

int my_find_prime_sup(int nb)
{
    if (my_is_prime(nb) == 1){
        return nb;
    }
    for (int i = nb + 1; 1 == 1; i++){
        if (my_is_prime(i) == 1){
            return i;
        }
    }
}
