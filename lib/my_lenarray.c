/*
** EPITECH PROJECT, 2022
** my_strlen_array
** File description:
** count line in array
*/

#include "my.h"

int my_lenarray(char **array)
{
    int i = 0;

    for (; array[i]; i++);
    return (i);
}
