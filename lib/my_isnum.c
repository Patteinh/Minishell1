/*
** EPITECH PROJECT, 2022
** my_isnum
** File description:
** isnum
*/

#include "my.h"

int my_isnum(char **array)
{
    for (int i = 0; array[1][i]; i++) {
        char c = array[1][i];
        if (c < 48 || (c > 57 && c < 65) || (c > 90 && c < 97) || c > 122)
            return (1);
    }
    return (0);
}
