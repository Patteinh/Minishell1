/*
** EPITECH PROJECT, 2022
** my_ischar
** File description:
** ischar
*/

#include "my.h"

int my_ischar(char c)
{
    if (c < 65 || (c > 90 && c < 97) || c > 122)
        return (1);
    return (0);
}
