/*
** EPITECH PROJECT, 2022
** my_putstr_array
** File description:
** print line array
*/

#include "my.h"

void my_parray(char **array)
{
    for (int i = 0; array[i]; i++) {
        if (i == my_lenarray(array) - 1) {
            my_printf("%s\n", array[i]);
            continue;
        }
        my_printf("%s ", array[i]);
    }
}
